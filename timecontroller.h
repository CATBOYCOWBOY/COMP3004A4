#ifndef TIMECONTROLLER_H
#define TIMECONTROLLER_H
#include <QObject>
#include <QThread>
#include <QMainWindow>
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
    TimeUpdater *timeUpdater;
    QThread *qthread;
    Ui::MainWindow *mw;
    QObject *parent;
};

#endif // TIMECONTROLLER_H
