#ifndef LOGSCONTROLLER_H
#define LOGSCONTROLLER_H
#include <QThread>
#include <QMainWindow>
#include <QVector>
#include <QtCore>
#include <QString>
#include "constants.h"
#include "neuresetController.h"
#include "ui_mainwindow.h"


class LogsController : public NeuresetController {
    Q_OBJECT
    public:
        // constructor
        LogsController(QObject *parent = nullptr, Ui::MainWindow *mw = nullptr, int i = -1);

        // destructor
        ~LogsController();

        // member functions
        QList<QStringList> parseLogs();
        void updateUi(int id, QStringList data);
        QString logsToString(int sessionId, QString startTime, QString endTime, QString startBaseline, QString endBaseline);
        void writeLogsToComputer();
        void writeLogsToDevice();


    public slots:
        void onUpButtonPressed(int);
        void onDownButtonPressed(int);
        void onPlayButtonPressed(int);
        void onPauseButtonPressed(int);
        void onStopButtonPressed(int);

        void addSessionToLogs(const QString&);     
    
    private:
        QList<QStringList> sessionsList;
        Ui::MainWindow *ui;
        int controllerId;
};

#endif // LOGS_H
