#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  timeController = new TimeController();
  this->computerView = new ComputerView(this);
  ui->setupUi(this);
  uiSetup();

  treatmentController = new TreatmentController(this, ui, TREATMENT_TAB_INDEX);
}

MainWindow::~MainWindow()
{
  delete ui;
  delete timeController;
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






void MainWindow::updateTime()
{
    *currentDateTime = QDateTime::currentDateTime();
    ui->dateTimeDisplay->setText(currentDateTime->toString());
}

void MainWindow::on_pushButton_clicked()
{
    updateTime();
    ui->dateTimeDisplay->setText(currentDateTime->toString());
}

