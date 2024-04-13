#ifndef TIMECONTROLLER_H
#define TIMECONTROLLER_H

#include <QObject>
#include <QThread>
#include <QMainWindow>
#include <QTime>
#include <QDate>

#include "constants.h"
#include "neuresetController.h"
#include "ui_mainwindow.h"
#include "timeupdater.h"



class TimeController : public NeuresetController
{
    Q_OBJECT
public:
    explicit TimeController(QObject *parent = nullptr, Ui::MainWindow *ui = nullptr, int i = -1);
    ~TimeController();
    QString getTime();

public slots:
    void onDeviceTimeUpdate();
    void onUpButtonPressed(int);
    void onDownButtonPressed(int);
    void onPlayButtonPressed(int);
    void onPauseButtonPressed(int);
    void onStopButtonPressed(int);

signals:
    void deviceTimeUpdate();
    void shutOff();   

private:    
    void updateTimeDisplay();
    void setDateTime();
    void updateTempVals();

    qint64 secsDelay = 0;
    TimeUpdater *timeUpdater;
    QThread *qthread;
    Ui::MainWindow *mw;
    QObject *parent;

    QDateTime *currentDateTime = new QDateTime(QDateTime::currentDateTime());

    int controllerId;
    int tempYear = 0;
    int tempMonth = 0;
    int tempDay = 0;
    int tempHour = 0;
    int tempMinute = 0;

    bool viewTime = true;
    bool setYear = false;
    bool setMonth = false;
    bool setDay = false;
    bool setHour = false;
    bool setMinute = false;

    QDate tempDate;
    QTime tempTime;
    QDateTime tempDateTime;
};

#endif // TIMECONTROLLER_H
