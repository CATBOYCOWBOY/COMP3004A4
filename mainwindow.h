#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDateTime>
#include <QMainWindow>
#include <QThread>
#include <QMutex>
#include "computerview.h"
#include "timecontroller.h"
#include "LogsController.h"
#include "treatmentcontroller.h"
#include "menucontroller.h"
#include "CustomWidgets/lightwithlabel.h"

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

  void on_powerButton_clicked();

  void testTreatmentLog(const QString&);

  void testSessionLogs(const QString&);

private:
  Ui::MainWindow *ui;
  ComputerView *computerView;
  TimeController *timeController;
  TreatmentController *treatmentController;
  MenuController *menuController;

  void uiSetup();

  void connectNeuresetController(NeuresetController*);

  int viewSelectedTabIndex;

  LogsController *logsController;

  bool isBatterySuffient;
  bool areAllEEGNodesConnected;
};
#endif // MAINWINDOW_H
