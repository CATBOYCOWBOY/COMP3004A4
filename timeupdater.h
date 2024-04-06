#ifndef TIMEUPDATER_H
#define TIMEUPDATER_H
#include <QObject>


class TimeUpdater : public QObject
{
    Q_OBJECT
public:
    explicit TimeUpdater();
public slots:
    void onShutOff();
    void run();
signals:
    void shutOff();
    void updateTime();
private:
    bool systemRunning;
};

#endif // TIMEUPDATER_H
