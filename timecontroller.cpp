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

void TimeController::onDeviceTimeUpdate()
{
    qDebug() << "onDeviceTimeUpdate";
}

void TimeController::updateTime()
{
    *currentDateTime = QDateTime::currentDateTime();
    mw->dateTimeDisplay->setText(currentDateTime->toString());
}
