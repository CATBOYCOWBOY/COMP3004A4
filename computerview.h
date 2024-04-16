#ifndef COMPUTERVIEW_H
#define COMPUTERVIEW_H

#include <QMainWindow>
#include <QtCore>

namespace Ui {
  class ComputerView;
}

class ComputerView : public QMainWindow
{
  Q_OBJECT

public:
  explicit ComputerView(QWidget *parent = nullptr);
  ~ComputerView();

private slots:
    void on_refreshButton_clicked();

private:
  Ui::ComputerView *ui;
  void readLogs();
};

#endif // COMPUTERVIEW_H
