#include "timeupdater.h"
#include <QThread>
#include <QDebug>

TimeUpdater::TimeUpdater()
{
    systemRunning = true;
}

void TimeUpdater::onShutOff()
{
    systemRunning = false;
}

void TimeUpdater::run()
{
    while (systemRunning){
        emit updateTime();
        QThread::msleep(1000);
    }
    emit shutOff();
}
