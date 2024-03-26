#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  this->computerView = new ComputerView(this);
  ui->setupUi(this);
  uiSetup();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::uiSetup()
{
  this->setStyleSheet(APP_STYLE_GLOBAL);
  ui->primaryTabs->setTabText(0, TREATMENT_TAB_TEXT);
  ui->primaryTabs->setTabText(1, LOGS_TAB_TEXT);
  ui->primaryTabs->setTabText(2, SETTINGS_TAB_TEXT);
}

void MainWindow::on_computerViewAction_triggered()
{
  computerView->show();
}

