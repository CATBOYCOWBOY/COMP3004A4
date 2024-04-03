#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDateTime>
#include <QMainWindow>
#include <QThread>
#include <QMutex>
#include "computerview.h"
#include "treatmentcontroller.h"

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

private slots:
  void on_computerViewAction_triggered();
  void on_menuButton_clicked();
  void on_upButton_clicked();
  void on_downButton_clicked();
  void on_playButton_clicked();
  void on_pauseButton_clicked();
  void on_stopButton_clicked();

private:
  Ui::MainWindow *ui;
  ComputerView *computerView;
  void uiSetup();

  QDateTime *currentDateTime = new QDateTime(QDateTime::currentDateTime());
  TreatmentController *treatmentController;

  bool isBatterySuffient;
  bool areAllEEGNodesConnected;


};
#endif // MAINWINDOW_H
