#ifndef LOGSCONTROLLER_H
#define LOGSCONTROLLER_H
#include <QThread>
#include <QMainWindow>
#include <QVector>
#include <QtCore>
#include <QString>
#include "Session.h"
#include "constants.h"
#include "neuresetController.h"
#include "eegsensor.h"
#include "ui_mainwindow.h"


class LogsController : public NeuresetController {
    Q_OBJECT
    public:
        // constructor
        LogsController(QObject *parent = nullptr, Ui::MainWindow *mw = nullptr, int i = -1);

        // destructor
        ~LogsController();

        // member functions
        void addSession();
        void uploadLogsToComputer();
        QString logsToString();
        void parseLogs();
        QVector<Session> *sessions;

    public slots:
        void onUpButtonPressed(int);
        void onDownButonPressed(int);
        void onPlayButtonPressed(int);
        void onPauseButonPressed(int);
        void onStopButtonPressed(int);

//    signals:
//        void uploadLogsToComputerButtonClicked();

    private:
        Ui::MainWindow *ui;
        int controllerId;
};

#endif // LOGS_H
