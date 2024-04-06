#include "menucontroller.h"
#include "constants.h"

#include <QString>

MenuController::MenuController(QObject *parent, Ui::MainWindow *mw, int i)
  : NeuresetController{parent}, ui(mw), selectedOptionIndex(0), controllerId(i)
{
  if (!parent || !mw || i < 0)
  {
    exit(-1);
  }
  labelOptions[0] = ui->menuTabTreatment;
  labelOptions[1] = ui->menuTabLogs;
  labelOptions[2] = ui->menuTabSettings;
  setupUi();
}

void MenuController::onUpButtonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }
  labelOptions[selectedOptionIndex]->setStyleSheet(QString::fromStdString(DEFAULT_MENU_STYLE));
  selectedOptionIndex = (selectedOptionIndex + 2) % 3;
  labelOptions[selectedOptionIndex]->setStyleSheet(QString::fromStdString(HIGHLIGHTED_STYLE));
}

void MenuController::onDownButonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }
  labelOptions[selectedOptionIndex]->setStyleSheet(QString::fromStdString(DEFAULT_MENU_STYLE));
  selectedOptionIndex = (selectedOptionIndex + 1) % 3;
  labelOptions[selectedOptionIndex]->setStyleSheet(QString::fromStdString(HIGHLIGHTED_STYLE));
}

void MenuController::onPlayButtonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }
  ui->primaryTabs->setCurrentIndex(selectedOptionIndex);
}

void MenuController::onPauseButonPressed(int)
{

}

void MenuController::onStopButtonPressed(int)
{

}

void MenuController::setupUi()
{
  labelOptions[selectedOptionIndex]->setStyleSheet(QString::fromStdString(HIGHLIGHTED_STYLE));
  ui->menuTabTreatment->setText(QString::fromStdString("Neureset EEG Treatment"));
  ui->menuTabTreatment->setAlignment(Qt::AlignCenter);
  ui->menuTabSettings->setText(QString::fromStdString("Date/Time Settings"));
  ui->menuTabSettings->setAlignment(Qt::AlignCenter);
  ui->menuTabLogs->setAlignment(Qt::AlignCenter);
  ui->menuTabLogs->setText(QString::fromStdString("Treatment Logs"));
}
