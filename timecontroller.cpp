#include "timecontroller.h"
#include <QDebug>

TimeController::TimeController(QObject* parent, Ui::MainWindow* ui)
{
    this->parent = parent;
    mw = ui;
    timeUpdater = new TimeUpdater();
    qthread = new QThread();
    timeUpdater->moveToThread(qthread);
    connect(qthread, &QThread::started, timeUpdater, &TimeUpdater::run);
    connect(timeUpdater, &TimeUpdater::shutOff, qthread, &QThread::quit, Qt::DirectConnection);
    connect(qthread, &QThread::finished, timeUpdater, &TimeUpdater::deleteLater);
    connect(timeUpdater, &TimeUpdater::updateTime, this, &TimeController::onDeviceTimeUpdate, Qt::DirectConnection);
    connect(this, &TimeController::shutOff, timeUpdater, &TimeUpdater::onShutOff, Qt::DirectConnection);
    qthread->start();
}
TimeController::~TimeController()
{
    emit shutOff();
}

QString TimeController::getTime()
{
    return (currentDateTime->addSecs(secsDelay)).toString();
}

void TimeController::onDeviceTimeUpdate()
{
    qDebug() << "onDeviceTimeUpdate";
    *currentDateTime = QDateTime::currentDateTime();
    qDebug() << getTime();
    //updateTime();
}

void TimeController::updateRealTime()
{
    *currentDateTime = QDateTime::currentDateTime();
    //mw->dateTimeDisplay->setText(getTime());
}

void TimeController::setDateTime() //update the secondsDelay value
{
    tempYear = 0;
    tempMonth = 0;
    tempDay = 0;
    tempHour = 0;
    tempMinute = 0;
    tempDate = QDate(tempYear, tempMonth, tempDay);
    tempTime = QTime(tempHour, tempMinute, 0, 0);
    tempDateTime = QDateTime(tempDate, tempTime);
    updateRealTime();
    secsDelay = currentDateTime->secsTo(tempDateTime);
}
