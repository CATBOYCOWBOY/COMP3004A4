#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDateTime>
#include <QMainWindow>
#include <QThread>
#include <QMutex>
#include "computerview.h"
#include "timecontroller.h"
#include "treatmentcontroller.h"
#include "menucontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

signals:
  void upButtonClicked(int);
  void downButtonClicked(int);
  void playButtonClicked(int);
  void pauseButtonClicked(int);
  void stopButtonClicked(int);

private slots:
  void on_computerViewAction_triggered();
  void on_menuButton_clicked();
  void on_upButton_clicked();
  void on_downButton_clicked();
  void on_playButton_clicked();
  void on_pauseButton_clicked();
  void on_stopButton_clicked();

  void on_primaryTabs_currentChanged(int index);

private:
  Ui::MainWindow *ui;
  ComputerView *computerView;
  TimeController *timeController;
  void uiSetup();

  void connectNeuresetController(NeuresetController*);

  int viewSelectedTabIndex;

  TreatmentController *treatmentController;
  MenuController *menuController;

  bool isBatterySuffient;
  bool areAllEEGNodesConnected;
};
#endif // MAINWINDOW_H
