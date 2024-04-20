#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow), viewSelectedTabIndex(MENU_TAB_INDEX)
{
  ui->setupUi(this);
  // setup led light
  uiSetup();

  computerView = new ComputerView(this);

  timeController = new TimeController(this, ui, SETTINGS_TAB_INDEX);
  connectNeuresetController(timeController);

  logsController = new LogsController(this, ui, LOGS_TAB_INDEX);
  connectNeuresetController(logsController);

  treatmentController = new TreatmentController(this, ui, timeController,TREATMENT_TAB_INDEX);
  connectNeuresetController(treatmentController);

  menuController = new MenuController(this, ui, MENU_TAB_INDEX);
  connectNeuresetController(menuController);

  // connect treatment controller log treatment to logs controller
  connect(treatmentController, &TreatmentController::logTreatment, this, &MainWindow::testTreatmentLog, Qt::DirectConnection);
  connect(treatmentController, &TreatmentController::logTreatment, logsController, &LogsController::addSessionToLogs, Qt::DirectConnection);
}

MainWindow::~MainWindow()
{
  delete timeController;
  delete treatmentController;
  delete logsController;
  delete computerView;
  delete ui;
}

void MainWindow::uiSetup()
{
  this->setStyleSheet(APP_STYLE_GLOBAL);
  ui->treatmentProgressLabel->setAlignment(Qt::AlignCenter);
  ui->treatmentProgress->setValue(0);
  ui->primaryTabs->setTabText(0, TREATMENT_TAB_TEXT);
  ui->primaryTabs->setTabText(1, LOGS_TAB_TEXT);
  ui->primaryTabs->setTabText(2, SETTINGS_TAB_TEXT);
//  ui->dateTimeDisplay->setText(currentDateTime->toString());
  ui->primaryTabs->setTabText(LOGS_TAB_INDEX, LOGS_TAB_TEXT);
  ui->primaryTabs->setTabText(SETTINGS_TAB_INDEX, SETTINGS_TAB_TEXT);
  ui->primaryTabs->setTabText(MENU_TAB_INDEX, MENU_TAB_TEXT);
  ui->primaryTabs->setCurrentIndex(viewSelectedTabIndex);
}

void MainWindow::connectNeuresetController(NeuresetController* controller)
{
  connect(this, &MainWindow::upButtonClicked, controller, &NeuresetController::onUpButtonPressed);
  connect(this, &MainWindow::downButtonClicked, controller, &NeuresetController::onDownButtonPressed);
  connect(this, &MainWindow::playButtonClicked, controller, &NeuresetController::onPlayButtonPressed);
  connect(this, &MainWindow::pauseButtonClicked, controller, &NeuresetController::onPauseButtonPressed);
  connect(this, &MainWindow::stopButtonClicked, controller, &NeuresetController::onStopButtonPressed);
}

void MainWindow::on_computerViewAction_triggered()
{
  computerView->show();
}

void MainWindow::on_menuButton_clicked()
{
  ui->primaryTabs->setCurrentIndex(MENU_TAB_INDEX);
}

void MainWindow::on_upButton_clicked()
{
  emit upButtonClicked(viewSelectedTabIndex);
}

void MainWindow::on_downButton_clicked()
{
  emit downButtonClicked(viewSelectedTabIndex);
}

void MainWindow::on_playButton_clicked()
{
  emit playButtonClicked(viewSelectedTabIndex);
}

void MainWindow::on_pauseButton_clicked()
{
  emit pauseButtonClicked(viewSelectedTabIndex);
}

void MainWindow::on_stopButton_clicked()
{
  emit stopButtonClicked(viewSelectedTabIndex);
}


void MainWindow::on_primaryTabs_currentChanged(int index)
{
  viewSelectedTabIndex = index;
}

void MainWindow::on_powerButton_clicked()
{
  QCoreApplication::exit();
}

void MainWindow::testTreatmentLog(const QString &string) {}

void MainWindow::testSessionLogs(const QString &str) {}
