#ifndef TREATMENTCONTROLLER_H
#define TREATMENTCONTROLLER_H

#include "neuresetController.h"

class TreatmentController: public NeuresetController
{
public:
  TreatmentController();

public slots:
  void onUpButtonPressed(int);
  void onDownButonPressed(int);
  void onPlayButtonPressed(int);
  void onPauseButonPressed(int);
  void onStopButtonPressed(int);
};

#endif // TREATMENTCONTROLLER_H
