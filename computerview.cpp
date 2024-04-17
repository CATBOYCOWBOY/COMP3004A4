#include "computerview.h"
#include "ui_computerview.h"

ComputerView::ComputerView(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::ComputerView)
{
  ui->setupUi(this);
  ui->tableWidget_Item_Data->setRowCount(100);
  ui->tableWidget_Item_Data->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
}

ComputerView::~ComputerView()
{
  delete ui;
}

void ComputerView::readLogs() {
    QFile CSVFile(QCoreApplication::applicationDirPath() + "/data.csv");
    // For testing, copy data.csv to ~/build-COMP3004A4-Desktop-Debug/COMP3004A4 path

    if (CSVFile.open(QIODevice::ReadWrite)) {
      qDebug() << "here";
      QTextStream Stream(&CSVFile);
      int rowIndex = 0;
      while (Stream.atEnd() == false) {
          QString lineData = Stream.readLine();
          QStringList data = lineData.split(",");

          for (int columnIndex = 0 ; columnIndex < data.length(); columnIndex++) {
              ui->tableWidget_Item_Data->setItem(rowIndex, columnIndex, new QTableWidgetItem(data.at(columnIndex)));
          }
          rowIndex ++;
      }
    }
}

void ComputerView::on_refreshButton_clicked()
{
    readLogs();
}

