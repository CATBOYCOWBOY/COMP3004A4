#include "computerview.h"
#include "ui_computerview.h"

ComputerView::ComputerView(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::ComputerView)
{
  ui->setupUi(this);
}

ComputerView::~ComputerView()
{
  delete ui;
}
