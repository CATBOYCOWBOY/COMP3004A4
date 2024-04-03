#include "treatmentcontroller.h"
#include "constants.h"

TreatmentController::TreatmentController(QObject* parent, Ui::MainWindow *mw, int i) : ui(mw), id(i)
{
  if (!parent || !mw || i < 0)
  {
    exit(-1);
  }
  ui->primaryTabs->setTabText(TREATMENT_TAB_INDEX, TREATMENT_TAB_TEXT);
  ui->treatmentProgressLabel->setAlignment(Qt::AlignCenter);
  ui->treatmentProgress->setValue(0);
}

void TreatmentController::onUpButtonPressed(int)
{

}

void TreatmentController::onDownButonPressed(int)
{

}

void TreatmentController::onPlayButtonPressed(int)
{

}

void TreatmentController::onPauseButonPressed(int)
{

}

void TreatmentController::onStopButtonPressed(int)
{

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

}
