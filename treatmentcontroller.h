#ifndef TREATMENTCONTROLLER_H
#define TREATMENTCONTROLLER_H

#include <QThread>
#include <QMutex>
#include <QVector>
#include "constants.h"
#include "neuresetController.h"
#include "ui_mainwindow.h"
#include "eegsensor.h"

class TreatmentController: public NeuresetController
{
  Q_OBJECT
public:
  TreatmentController(QObject *parent = nullptr, Ui::MainWindow *mw = nullptr, int i = -1);
  ~TreatmentController();

signals:
  void treatmentStarted();
  void treatmentPaused();
  void treatmentUnpaused();
  void treatmentStopped();
  void batteryLow();
  void sensorDisconnected();
  void batteryReset();
  void connectionReset();
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

  void onFiveMinutesDisconnected();
private:
  Ui::MainWindow *ui;
  QMutex* controllerMutex;
  int batteryTreatmentsLeft;
  bool isBatteryLow = false;
  bool isCableDisconnected = false;
  bool isTreatmentRunning = true;
  bool isTreatmentPaused = false;

  int controllerId;

  int selectedSensorId;

  QString prevTreatmentString;

  EEGSensor* sensors [NUM_SITES];
  QThread* threads[NUM_SITES];

  int unfinishedSensors;
  double startingSumBaseline;
  double endingSumBaseline;

  QVector<double> defaultYSeries;
  QVector<double> xSeries;

  void initializeSensorsAndThreads();
  void connectSensorThreads(EEGSensor*, QThread*);
  void updateTreatmentString();
};

#endif // TREATMENTCONTROLLER_H
