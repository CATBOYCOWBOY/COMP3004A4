#ifndef TIMECONTROLLER_H
#define TIMECONTROLLER_H
#include <QObject>
#include <QThread>
#include <QMainWindow>
#include <QTime>
#include <QDate>
#include "ui_mainwindow.h"
#include "timeupdater.h"

class TimeController : public QObject
{
    Q_OBJECT
public:
    explicit TimeController(QObject *parent = nullptr, Ui::MainWindow *ui = nullptr, int i = -1);
    ~TimeController();
    QString getTime();

public slots:
    void onDeviceTimeUpdate();
signals:
    void deviceTimeUpdate();
    void shutOff();
private:
    void updateRealTime();
    void setDateTime();
    qint64 secsDelay = 0;
    TimeUpdater *timeUpdater;
    QThread *qthread;
    Ui::MainWindow *mw;
    QObject *parent;
    QDateTime *currentDateTime = new QDateTime(QDateTime::currentDateTime());

    int controllerId;
    int tempYear;
    int tempMonth;
    int tempDay;
    int tempHour;
    int tempMinute;
    QDate tempDate;
    QTime tempTime;
    QDateTime tempDateTime;
};

#endif // TIMECONTROLLER_H
