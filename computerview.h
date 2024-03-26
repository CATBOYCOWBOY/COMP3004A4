#ifndef COMPUTERVIEW_H
#define COMPUTERVIEW_H

#include <QMainWindow>

namespace Ui {
  class ComputerView;
}

class ComputerView : public QMainWindow
{
  Q_OBJECT

public:
  explicit ComputerView(QWidget *parent = nullptr);
  ~ComputerView();

private:
  Ui::ComputerView *ui;
};

#endif // COMPUTERVIEW_H
