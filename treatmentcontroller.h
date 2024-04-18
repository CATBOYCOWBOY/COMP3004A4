 #ifndef TREATMENTCONTROLLER_H
#define TREATMENTCONTROLLER_H

#include <QThread>
#include <QMutex>
#include <QVector>
#include "constants.h"
#include "neuresetController.h"
#include "ui_mainwindow.h"
#include "eegsensor.h"
#include "timecontroller.h"
#include "LogsController.h"
#include "CustomWidgets/lightwithlabel.h"

class TreatmentController: public NeuresetController
{
  Q_OBJECT
public:
  TreatmentController(
    QObject *parent = nullptr,
    Ui::MainWindow *mw = nullptr,
    TimeController *tc = nullptr,
    int i = -1,
    LogsController *lc = nullptr
  );
  ~TreatmentController();

signals:
  void treatmentStarted();
  void treatmentPaused();
  void treatmentUnpaused();
  void treatmentStopped();
  void treatmentDone();
  void batteryLow();
  void sensorDisconnected();
  void batteryReset();
  void connectionReset();
  void logTreatment(const QString&);
  void shutOff();

  // signals only for updating UI from threaded processes (don't include in UML)
  void timeRemainingChanged(const QString&);
  void treatmentPercentageChanged(int);
  void dataSeriesUpdated(const QVector<double>&, const QVector<double>&, bool);
  void graphRedraw(QCustomPlot::RefreshPriority);

private slots:

  void onUpButtonPressed(int);
  void onDownButtonPressed(int);
  void onPlayButtonPressed(int);
  void onPauseButtonPressed(int);
  void onStopButtonPressed(int);

  void onBatteryLowCondition();
  void onBatteryResetCondition();
  void onCableDisconnect();
  void onCableReconnect();

  void onWaveFormUpdate(int);
  void onSensorFinished(double);
  void onSensorStarted(double);
  void onCycleComplete();
  void onApply();
  void onApplyEnded();

  void onFiveMinutesDisconnected();
private:
  Ui::MainWindow *ui;
  TimeController *timeController;
  LogsController *logsController;
  QMutex* controllerMutex;

  LightWithLabel *connectionLight;
  LightWithLabel *treatmentLight;
  LightWithLabel *batteryLight;

  int batteryTreatmentsLeft;
  bool isBatteryLow = false;
  bool isCableDisconnected = false;
  bool isTreatmentRunning = true;
  bool isTreatmentPaused = false;

  int controllerId;

  int selectedSensorId;

  EEGSensor* sensors [NUM_SITES];
  QThread* threads[NUM_SITES];

  int numCyclesRemaining; // number of treatment cycles and final analysis remaning, used for calculating progress
  int unfinishedSensors;
  int activeSensors;
  double startingSumBaseline;
  double endingSumBaseline;

  QVector<double> defaultYSeries;
  QVector<double> xSeries;

  QString treatmentStartTime;

  void initializeSensorsAndThreads();
  void connectSensorThreads(EEGSensor*, QThread*);
  void updateTreatmentString();

  int treatmentPercentage();
};

#endif // TREATMENTCONTROLLER_H
