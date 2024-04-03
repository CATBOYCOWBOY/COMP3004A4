#ifndef TREATMENTCONTROLLER_H
#define TREATMENTCONTROLLER_H

#include "neuresetController.h"
#include "ui_mainwindow.h"

class TreatmentController: public NeuresetController
{
  Q_OBJECT
public:
  TreatmentController(QObject *parent = nullptr, Ui::MainWindow *mw = nullptr, int i = -1);

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

private:
  Ui::MainWindow *ui;
  bool isBatteryLow = false;
  bool isCableDisconnected = false;
  bool isSystemRunning = true;

  int id;
};

#endif // TREATMENTCONTROLLER_H
