#include "treatmentcontroller.h"
#include "constants.h"

TreatmentController::TreatmentController(QObject* parent, Ui::MainWindow *mw, int i) : ui(mw), controllerId(i)
{
  if (!parent || !mw || i < 0)
  {
    exit(-1);
  }
  ui->primaryTabs->setTabText(TREATMENT_TAB_INDEX, TREATMENT_TAB_TEXT);
  ui->treatmentProgressLabel->setAlignment(Qt::AlignCenter);
  ui->treatmentProgress->setValue(0);
}

void TreatmentController::onUpButtonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }
}

void TreatmentController::onDownButonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }
}

void TreatmentController::onPlayButtonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }
}

void TreatmentController::onPauseButonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }
}

void TreatmentController::onStopButtonPressed(int i)
{
  if (controllerId != i)
  {
    return;
  }
}

void TreatmentController::onBatteryLowCondition()
{

}

void TreatmentController::onBatteryResetCondition()
{

}

void TreatmentController::onCableDisconnect()
{

}

void TreatmentController::onCableReconnect()
{

//}
