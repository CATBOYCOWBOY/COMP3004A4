#ifndef LOGS_H
#define LOGS_H

#include "Session.h"
#include <QVector>
#include <QtCore>
#include <QString>

class Logs {
    public:
        // constructor
        Logs();

        // destructor
        ~Logs();

        // member functions
        void uploadLogsToComputer();
        QString logsToString();
        void parseLogs();

    private:
        QVector<Session> sessions{};
};

#endif // LOGS_H
