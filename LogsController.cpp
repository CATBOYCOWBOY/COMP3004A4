#include "LogsController.h"
#include <QDebug>

LogsController::LogsController(QObject *parent = nullptr, Ui::MainWindow *mw = nullptr, int i) {
    this->parent = parent;
    mw = ui;
}

LogsController::LogsController() {}

LogsController::~LogsController() {}

void LogsController::parseLogsController() {
    // parse file
    QList<QStringList> dataList;
    QFile CSVFile(QCoreApplication::applicationDirPath() + "/logs.csv");
    if (CSVFile.open(QIODevice::ReadWrite)) {
        QTextStream stream(&CSVFile);
        while (stream.atEnd() == false) {
            QString line = stream.readLine();
            QStringList data = line.split(",");
            dataList.append(data);
        }
    }

//    // create and store session objects
//    QVector<Session> *sessionsTemp = new QVector<Session>;
//    for (int i = 0; i < dataList.size(); i++) {
//        Session *s = new Session(i+1, dataList[i][0], dataList[i][1], dataList[i][2].toInt(), dataList[i][3].toInt());
//        sessionsTemp.push_back(s);
//    }

//    // test print
//    for (int i = 0; i < sessionsTemp.size(); i++) {
//        qDebug() << sessionsTemp[i]->sessionToString();
//    }

//    return sessionsTemp;
 }

void LogsController::uploadLogsControllerToComputer() {

}

QString LogsController::LogsControllerToString() {
    return QString("womp womp");
}
