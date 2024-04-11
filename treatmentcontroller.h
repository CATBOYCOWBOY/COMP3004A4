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
#include "CustomWidgets/ledlight.h"

class TreatmentController: public NeuresetController
{
  Q_OBJECT
public:
  TreatmentController(QObject *parent = nullptr,
                      Ui::MainWindow *mw = nullptr,
                      TimeController *tc = nullptr,
                      int i = -1,
                      QList<LedLight*>* ledLights = nullptr);
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

public slots:
  void onUpButtonPressed(int);
  void onDownButonPressed(int);
  void onPlayButtonPressed(int);
  void onPauseButonPressed(int);
  void onStopButtonPressed(int);

  void onBatteryLowCondition();
  void onBatteryResetCondition();
  void onCableDisconnect();
  void onCableReconnect();

  void onWaveFormUpdate(int);
  void onSensorFinished(double);
  void onSensorStarted(double);
  void onCycleComplete();

  void onFiveMinutesDisconnected();
private:
  Ui::MainWindow *ui;
  QList<LedLight*>* ledLights;
  TimeController *timeController;
  QMutex* controllerMutex;
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
