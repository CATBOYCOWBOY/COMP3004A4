#ifndef NEURESETCONTROLLER_H
#define NEURESETCONTROLLER_H

#include <QObject>

class NeuresetController : public QObject
{
public:
  NeuresetController(QObject *parent = nullptr);
public slots:
  virtual void onUpButtonPressed(int) = 0;
  virtual void onDownButonPressed(int) = 0;
  virtual void onPlayButtonPressed(int) = 0;
  virtual void onPauseButonPressed(int) = 0;
  virtual void onStopButtonPressed(int) = 0;
};

#endif // NEURESETCONTROLLER_H
