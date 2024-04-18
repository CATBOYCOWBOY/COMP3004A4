#include <sstream>
#include "treatmentcontroller.h"
#include "constants.h"

TreatmentController::TreatmentController(QObject* parent, Ui::MainWindow *mw, TimeController *tc, int i, LogsController *lc) :
  ui(mw),
  timeController(tc),
  logsController(lc),
  controllerMutex(new QMutex()),
  batteryTreatmentsLeft(BATTERY_TREATMENT_CAPACITY),
  isTreatmentRunning(false),
  controllerId(i),
  selectedSensorId(0),
  numCyclesRemaining(0),
  unfinishedSensors(0),
  activeSensors(0),
  defaultYSeries(NUM_SAMPLES),
  xSeries(NUM_SAMPLES),
  treatmentStartTime("")
{
  if (!parent || !mw || i < 0)
  {
    exit(-1);
  }

  ui->primaryTabs->setTabText(TREATMENT_TAB_INDEX, TREATMENT_TAB_TEXT);
  ui->treatmentProgressLabel->setAlignment(Qt::AlignCenter);
  ui->treatmentProgress->setValue(0);

  std::stringstream labelText;
  labelText << "Sensor " << selectedSensorId + 1 << " readings";
  ui->waveLabel->setAlignment(Qt::AlignCenter);
  ui->waveLabel->setText(QString::fromStdString(labelText.str()));

  for (int i = 0; i < NUM_SAMPLES; i++)
  {
    defaultYSeries[i] = 0;
    xSeries[i] = i * (INTERVAL_END / NUM_SAMPLES);
  }

  ui->waveDisplay->addGraph();
  ui->waveDisplay->graph(0)->setData(xSeries, defaultYSeries);
  ui->waveDisplay->xAxis->setLabel(X_LABEL);
  ui->waveDisplay->yAxis->setLabel(Y_LABEL);
  ui->waveDisplay->xAxis->setRange(0, INTERVAL_END);
  ui->waveDisplay->yAxis->setRange(-800, 800); // max possible combined amplitude on 4 waves w/ amplitude 200
  ui->waveDisplay->replot();

  treatmentLight = new LightWithLabel(nullptr, "treatment", Qt::green);
  connectionLight = new LightWithLabel(nullptr, "contact", Qt::blue);
  batteryLight = new LightWithLabel(nullptr, "errors", Qt::red);

  treatmentLight->turnOff();
  connectionLight->turnOff();
  batteryLight->turnOff();

  ui->ledLayout->addWidget(connectionLight);
  ui->ledLayout->addWidget(treatmentLight);
  ui->ledLayout->addWidget(batteryLight);

  initializeSensorsAndThreads();

  connect(ui->batteryLowAction, &QAction::triggered, this, &TreatmentController::onBatteryLowCondition);
  connect(ui->batteryResetAction, &QAction::triggered, this, &TreatmentController::onBatteryResetCondition);
  connect(ui->disconnectTerminalAction, &QAction::triggered, this, &TreatmentController::onCableDisconnect);
  connect(ui->connectTerminalAction, &QAction::triggered, this, &TreatmentController::onCableReconnect);

  connect(this, &TreatmentController::timeRemainingChanged, ui->estimatedTimeLabel, &QLabel::setText, Qt::QueuedConnection);
  connect(this, &TreatmentController::treatmentPercentageChanged, ui->treatmentProgress, &QProgressBar::setValue, Qt::QueuedConnection);

  connect(this, &TreatmentController::dataSeriesUpdated, ui->waveDisplay->graph(0), &QCPGraph::setData, Qt::QueuedConnection);
  connect(this, &TreatmentController::graphRedraw, ui->waveDisplay, &QCustomPlot::replot, Qt::QueuedConnection);
}

TreatmentController::~TreatmentController()
{
  for (int i = 0; i < NUM_SITES; i++)
  {
    sensors[i]->onShutOff();
    threads[i]->wait();
  }

  for (int i = 0; i < NUM_SITES; i++)
  {
    delete threads[i];
  }
}

void TreatmentController::onUpButtonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }
  selectedSensorId = (selectedSensorId + 1) % NUM_SITES;

  std::stringstream labelText;
  labelText << "Sensor " << selectedSensorId + 1 << " readings";
  ui->waveLabel->setText(QString::fromStdString(labelText.str()));
  ui->waveDisplay->graph(0)->setData(xSeries, sensors[selectedSensorId]->getCurrentSeries());
  ui->waveDisplay->replot();
}

void TreatmentController::onDownButtonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }
  selectedSensorId = (selectedSensorId + NUM_SITES - 1) % NUM_SITES;

  std::stringstream labelText;
  labelText << "Sensor " << selectedSensorId + 1 << " readings";
  ui->waveLabel->setText(QString::fromStdString(labelText.str()));
  ui->waveDisplay->graph(0)->setData(xSeries, sensors[selectedSensorId]->getCurrentSeries());
  ui->waveDisplay->replot();
}

void TreatmentController::onPlayButtonPressed(int i)
{
  if (controllerId != i || batteryTreatmentsLeft == 0)
  {
    return;
  } else if (isTreatmentPaused)
  {
    isTreatmentPaused = false;
    emit treatmentUnpaused();
    return;
  } else if (batteryTreatmentsLeft == 0) {
    return;
  }
  qDebug() << "NEURESET STARTING TREATMENT";
  std::stringstream s;
  s << "Est. time remaining: ";
  // Time spent on feedback rounds + baseline calculations
  s << (NUM_FEEDBACK_ROUNDS * 5 + NUM_FEEDBACK_ROUNDS) + 5 << " s";
  ui->treatmentProgress->setValue(0);
  treatmentStartTime = timeController->getTime();
  startingSumBaseline = 0;
  endingSumBaseline = 0;
  connectionLight->solidOn();
  ui->estimatedTimeLabel->setText(QString::fromStdString(s.str()));
  emit treatmentStarted();
}

void TreatmentController::onPauseButtonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }

  if (!isTreatmentPaused)
    {
      isTreatmentPaused = true;
      emit treatmentPaused();
    }
}

void TreatmentController::onStopButtonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }
  qDebug() << "NEURESET STOPPING TREATMENT";
  ui->treatmentProgress->setValue(0);
  unfinishedSensors = 0;
  numCyclesRemaining = 0;
  ui->waveDisplay->graph(0)->setData(xSeries, defaultYSeries);
  ui->waveDisplay->replot();
  connectionLight->turnOff();
  emit treatmentStopped();
}

void TreatmentController::onBatteryLowCondition()
{
  batteryLight->solidOn();
  emit batteryLow();
}

void TreatmentController::onBatteryResetCondition()
{
  batteryLight->turnOff();
  batteryTreatmentsLeft = BATTERY_TREATMENT_CAPACITY;
  emit batteryReset();
}

void TreatmentController::onCableDisconnect()
{
  emit sensorDisconnected();
  connectionLight->turnOff();
  batteryLight->flashOn();
}

void TreatmentController::onCableReconnect()
{
  if (isTreatmentRunning)
    connectionLight->solidOn();
  batteryLight->turnOff();
  emit connectionReset();
}

void TreatmentController::onWaveFormUpdate(int i)
{
  if (i != selectedSensorId)
  {
    return;
  }
  emit dataSeriesUpdated(xSeries, sensors[selectedSensorId]->getCurrentSeries(), false);
  emit graphRedraw(QCustomPlot::rpRefreshHint);
}

void TreatmentController::onSensorFinished(double i)
{
  controllerMutex->lock();
  unfinishedSensors = unfinishedSensors - 1;
  endingSumBaseline = endingSumBaseline + i;
  numCyclesRemaining = numCyclesRemaining - 1;
  emit treatmentPercentageChanged(treatmentPercentage());


  if (unfinishedSensors == 0) // on completion of full treatment
  {
    qDebug() << "NEURESET TREATMENT DONE";
    isTreatmentRunning = false;
    isTreatmentPaused = false;
    batteryTreatmentsLeft -= 1;
    QString logString = treatmentStartTime +
                        QString::fromStdString(",") +
                        QString::number(startingSumBaseline / NUM_SITES)+
                        QString::fromStdString(",") +
                        timeController->getTime() +
                        QString::fromStdString(",") +
                        QString::number(endingSumBaseline / NUM_SITES);
    emit treatmentDone();
    emit logTreatment(logString);
    if (batteryTreatmentsLeft <= 1) {
      emit batteryLow();
    }
  }
  controllerMutex->unlock();
  emit timeRemainingChanged("");
}

void TreatmentController::onSensorStarted(double i)
{
  controllerMutex->lock();
  numCyclesRemaining = numCyclesRemaining + NUM_FEEDBACK_ROUNDS + 1; // 1 cycle for each feedback round, 1 for final analysis
  unfinishedSensors = unfinishedSensors + 1;
  startingSumBaseline = startingSumBaseline + i;
  controllerMutex->unlock();
}

void TreatmentController::onCycleComplete()
{
  controllerMutex->lock();
  numCyclesRemaining = numCyclesRemaining - 1;
  emit treatmentPercentageChanged(treatmentPercentage());

  std::stringstream s;
  s << "Est. seconds remaining: ";
  s << std::max(static_cast<int>((NUM_FEEDBACK_ROUNDS * 5 + NUM_FEEDBACK_ROUNDS) -
                        (NUM_FEEDBACK_ROUNDS * 5 + NUM_FEEDBACK_ROUNDS) *
                         static_cast<float>(treatmentPercentage()) / 100), 0)
    << " s";

  emit timeRemainingChanged(QString::fromStdString(s.str()));
  controllerMutex->unlock();
}

// when treatment application starts
void TreatmentController::onApply()
{
  controllerMutex->lock();
  activeSensors = activeSensors + 1;
  controllerMutex->unlock();
  if (activeSensors > 0) {
    treatmentLight->solidOn();
  }
}

// when treatment application ends
void TreatmentController::onApplyEnded()
{
  controllerMutex->lock();
  activeSensors = activeSensors - 1;
  controllerMutex->unlock();
  if (activeSensors == 0)
  {
    treatmentLight->turnOff();
  }
}

void TreatmentController::onFiveMinutesDisconnected()
{
  emit shutOff();
  QCoreApplication::exit();
}

void TreatmentController::initializeSensorsAndThreads()
{
  for (int i = 0; i < NUM_SITES; i++)
  {
    sensors[i] = new EEGSensor(nullptr, i);
    threads[i] = new QThread();

    connectSensorThreads(sensors[i], threads[i]);
    sensors[i]->moveToThread(threads[i]);
    threads[i]->start();
  }
}

int TreatmentController::treatmentPercentage()
{
  float de = static_cast<float>(NUM_SITES * NUM_FEEDBACK_ROUNDS + NUM_SITES);
  float num = static_cast<float>(NUM_SITES * NUM_FEEDBACK_ROUNDS + NUM_SITES - numCyclesRemaining);
  return static_cast<int>((num/de) * 100);
}

void TreatmentController::connectSensorThreads(EEGSensor *sensor, QThread *thread)
{
  connect(thread, &QThread::started, sensor, &EEGSensor::run);
  connect(sensor, &EEGSensor::shutOff, thread, &QThread::quit, Qt::DirectConnection);
  connect(thread, &QThread::finished, sensor, &EEGSensor::deleteLater);

  connect(this, &TreatmentController::treatmentStarted, sensor, &EEGSensor::onTreatmentStart, Qt::DirectConnection);
  connect(this, &TreatmentController::batteryLow, sensor, &EEGSensor::onBatteryLow, Qt::DirectConnection);
  connect(this, &TreatmentController::sensorDisconnected, sensor, &EEGSensor::onDisconnect, Qt::DirectConnection);

  connect(this, &TreatmentController::treatmentPaused, sensor, &EEGSensor::onTreatmentPause, Qt::DirectConnection);
  connect(this, &TreatmentController::treatmentUnpaused, sensor, &EEGSensor::onTreatmentUnpaused, Qt::DirectConnection);
  connect(this, &TreatmentController::treatmentStopped, sensor, &EEGSensor::onTreatmentStopped, Qt::DirectConnection);

  connect(this, &TreatmentController::batteryReset, sensor, &EEGSensor::onBatteryReset, Qt::DirectConnection);
  connect(this, &TreatmentController::connectionReset, sensor, &EEGSensor::onConnectionReset, Qt::DirectConnection);

  connect(sensor, &EEGSensor::treatmentEnded, this, &TreatmentController::onSensorFinished, Qt::DirectConnection);
  connect(sensor, &EEGSensor::treatmentStarted, this, &TreatmentController::onSensorStarted, Qt::DirectConnection);
  connect(sensor, &EEGSensor::frequencyUpdated, this, &TreatmentController::onWaveFormUpdate, Qt::DirectConnection);
  connect(sensor, &EEGSensor::cycleComplete, this, &TreatmentController::onCycleComplete, Qt::DirectConnection);

  connect(sensor, &EEGSensor::active, this, &TreatmentController::onApply, Qt::QueuedConnection);
  connect(sensor, &EEGSensor::inactive, this, &TreatmentController::onApplyEnded, Qt::QueuedConnection);

  connect(sensor, &EEGSensor::fiveMinutesDisconnected, this, &TreatmentController::onFiveMinutesDisconnected, Qt::DirectConnection);
}
