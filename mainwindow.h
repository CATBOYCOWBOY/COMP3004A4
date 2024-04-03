#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDateTime>
#include <QMainWindow>
#include <QThread>
#include <QMutex>
#include "computerview.h"
#include "timecontroller.h"

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

  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;
  ComputerView *computerView;
  TimeController *timeController;
  void uiSetup();
  void updateTime();

  QDateTime *currentDateTime = new QDateTime(QDateTime::currentDateTime());

  bool isBatterySuffient;
  bool areAllEEGNodesConnected;
};
#endif // MAINWINDOW_H
