#ifndef TIMECONTROLLER_H
#define TIMECONTROLLER_H
#include <QObject>
#include <QThread>
#include <QMainWindow>
#include <QTime>
#include "ui_mainwindow.h"
#include "timeupdater.h"

class TimeController : public QObject
{
    Q_OBJECT
public:
    explicit TimeController(QObject *parent = nullptr, Ui::MainWindow *ui = nullptr);
    ~TimeController();

public slots:
    void onDeviceTimeUpdate();
signals:
    void deviceTimeUpdate();
    void shutOff();
private:
    void updateTime();
    TimeUpdater *timeUpdater;
    QThread *qthread;
    Ui::MainWindow *mw;
    QObject *parent;
    QDateTime *currentDateTime = new QDateTime(QDateTime::currentDateTime());
};

#endif // TIMECONTROLLER_H
