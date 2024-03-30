#ifndef TIMECONTROLLER_H
#define TIMECONTROLLER_H
#include <QObject>
#include <QThread>
#include "timeupdater.h"

class TimeController : public QObject
{
    Q_OBJECT
public:
    explicit TimeController();
    ~TimeController();

public slots:
    void onDeviceTimeUpdate();
signals:
    void deviceTimeUpdate();
    void shutOff();
private:
    TimeUpdater *timeUpdater;
    QThread *qthread;

};

#endif // TIMECONTROLLER_H
