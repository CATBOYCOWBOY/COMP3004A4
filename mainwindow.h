#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "computerview.h"

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

private:
  Ui::MainWindow *ui;
  ComputerView *computerView;
  void uiSetup();

  bool isBatterySuffient;
  bool areAllEEGNodesConnected;
};
#endif // MAINWINDOW_H
