#include <sstream>
#include "treatmentcontroller.h"
#include "constants.h"

TreatmentController::TreatmentController(QObject* parent, Ui::MainWindow *mw, TimeController *tc, int i, QList<LedLight*>* leds) :
  ui(mw),
  ledLights(leds),
  timeController(tc),
  controllerMutex(new QMutex()),
  batteryTreatmentsLeft(BATTERY_TREATMENT_CAPACITY),
  isTreatmentRunning(false),
  controllerId(i),
  selectedSensorId(0),
  numCyclesRemaining(0),
  unfinishedSensors(0),
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

  connect(ui->batteryLowAction, &QAction::triggered, this, &TreatmentController::onBatteryLowCondition);
  connect(ui->batteryResetAction, &QAction::triggered, this, &TreatmentController::onBatteryResetCondition);
  connect(ui->disconnectTerminalAction, &QAction::triggered, this, &TreatmentController::onCableDisconnect);
  connect(ui->connectTerminalAction, &QAction::triggered, this, &TreatmentController::onCableReconnect);

  //connect with LED behavior
  ledLights->at(0)->toggle(); //assume the eeg is connected at the beginning the device is on, blue light is on
  connect(this, &TreatmentController::sensorDisconnected, ledLights->at(0), &LedLight::toggle); // if disconnect, turn off blue light
  connect(this, &TreatmentController::connectionReset, ledLights->at(0), &LedLight::toggle); // if reconnect, turn on blue light
  connect(this, &TreatmentController::treatmentStarted, ledLights->at(1), &LedLight::toggle); // if treatment starts, turn on green light

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

  initializeSensorsAndThreads();
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

void TreatmentController::onDownButonPressed(int i)
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
  }
  if (isTreatmentPaused)
  {
    isTreatmentPaused = false;
    emit treatmentUnpaused();
    return;
  }
  qDebug() << "NEURESET STARTING TREATMENT";
  ui->treatmentProgress->setValue(0);
  treatmentStartTime = timeController->getTime();
  emit treatmentStarted();
}

void TreatmentController::onPauseButonPressed(int i)
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
  emit treatmentStopped();
}

void TreatmentController::onBatteryLowCondition()
{
  emit batteryLow();
}

void TreatmentController::onBatteryResetCondition()
{
  batteryTreatmentsLeft = BATTERY_TREATMENT_CAPACITY;
  emit batteryReset();
}

void TreatmentController::onCableDisconnect()
{
  emit sensorDisconnected();
}

void TreatmentController::onCableReconnect()
{
  emit connectionReset();
}

void TreatmentController::onWaveFormUpdate(int i)
{
  if (i != selectedSensorId)
  {
    return;
  }
  controllerMutex->lock();
  ui->waveDisplay->graph(0)->setData(xSeries, sensors[selectedSensorId]->getCurrentSeries());
  ui->waveDisplay->replot();
  controllerMutex->unlock();
}

void TreatmentController::onSensorFinished(double i)
{
  controllerMutex->lock();
  qDebug() << "Sensor finished";
  unfinishedSensors = unfinishedSensors - 1;
  endingSumBaseline = endingSumBaseline + i;
  numCyclesRemaining = numCyclesRemaining - 1;
  ui->treatmentProgress->setValue(treatmentPercentage());

  if (unfinishedSensors == 0) // on completion of full treatment
  {
    qDebug() << "NEURESET TREATMENT DONE";
    isTreatmentRunning = false;
    isTreatmentPaused = false;
    batteryTreatmentsLeft -= 1;
    qDebug() << "init baseline: " << startingSumBaseline / NUM_SITES;
    qDebug() << "end baseline: " << endingSumBaseline / NUM_SITES;
    QString logString = treatmentStartTime +
                        QString::fromStdString(",") +
                        QString::number(startingSumBaseline / NUM_SITES)+
                        QString::fromStdString(",") +
                        timeController->getTime() +
                        QString::fromStdString(",") +
                        QString::number(endingSumBaseline / NUM_SITES);
    emit logTreatment(logString);
  }
  controllerMutex->unlock();
}

void TreatmentController::onSensorStarted(double i)
{
  controllerMutex->lock();
  qDebug() << "Sensor started";
  numCyclesRemaining = numCyclesRemaining + NUM_FEEDBACK_ROUNDS + 1; // 1 cycle for each feedback round, 1 for final analysis
  unfinishedSensors = unfinishedSensors + 1;
  startingSumBaseline = startingSumBaseline + i;
  controllerMutex->unlock();
}

void TreatmentController::onCycleComplete()
{
  controllerMutex->lock();
  numCyclesRemaining = numCyclesRemaining - 1;
  ui->treatmentProgress->setValue(treatmentPercentage());
  controllerMutex->unlock();
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

  connect(sensor, &EEGSensor::fiveMinutesDisconnected, this, &TreatmentController::onFiveMinutesDisconnected, Qt::DirectConnection);  
}
