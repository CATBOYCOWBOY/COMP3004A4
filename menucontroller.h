#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <neuresetController.h>
#include "ui_mainwindow.h"

class MenuController : public NeuresetController
{
  Q_OBJECT
public:
  explicit MenuController(QObject *parent = nullptr, Ui::MainWindow *mw = nullptr, int i = -1);

public slots:
  void onUpButtonPressed(int);
  void onDownButtonPressed(int);
  void onPlayButtonPressed(int);
  void onPauseButtonPressed(int);
  void onStopButtonPressed(int);

private:
  Ui::MainWindow *ui;
  int selectedOptionIndex;
  int controllerId;
  QLabel *labelOptions[3];
;
  void setupUi();
};

#endif // MENUCONTROLLER_H
