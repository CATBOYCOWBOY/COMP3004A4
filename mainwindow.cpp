#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  uiSetup();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::uiSetup()
{
  QPushButton* test = new QPushButton();
  QWidget* widget = new QWidget();
  QVBoxLayout* scrollChild = new QVBoxLayout(widget);
  scrollChild->addWidget(test);
  ui->setupUi(this);
  this->setStyleSheet(APP_STYLE_GLOBAL);
  ui->primaryTabs->setTabText(0, NEURESET_TAB_TEXT);
  ui->primaryTabs->setTabText(1, COMPUTER_TAB_TEXT);
  ui->neuresetView->setStyleSheet(SCROLL_AREA_STYLE);
  ui->neuresetView->setWidget(widget);
  ui->neuresetView->setWidgetResizable(true);
}
