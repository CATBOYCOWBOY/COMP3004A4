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

  treatmentController = new TreatmentController(this, ui, TREATMENT_TAB_INDEX);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::uiSetup()
{
  this->setStyleSheet(APP_STYLE_GLOBAL);
  ui->dateTimeDisplay->setText(currentDateTime->toString());
  ui->primaryTabs->setTabText(1, LOGS_TAB_TEXT);
  ui->primaryTabs->setTabText(2, SETTINGS_TAB_TEXT);
}

void MainWindow::on_computerViewAction_triggered()
{
  computerView->show();
}

void MainWindow::on_menuButton_clicked()
{
  qDebug() << "menu btton";
}

void MainWindow::on_upButton_clicked()
{
  qDebug() << "up button";
}

void MainWindow::on_downButton_clicked()
{
  qDebug() << "down button";
}

void MainWindow::on_playButton_clicked()
{
  qDebug() << "play button";
}

void MainWindow::on_pauseButton_clicked()
{
  qDebug() << "pause button";
}

void MainWindow::on_stopButton_clicked()
{
  qDebug() << "stop button";
}

