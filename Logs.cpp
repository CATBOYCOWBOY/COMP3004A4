#include "Logs.h"

Logs::Logs() {
    // look in logs.txt and parse data
    parseLogs();
}

Logs::~Logs() {
//    for (int i = 0; i < this->sessions.size(); i++) {
//        delete this->sessions[i];
//    }
}

void Logs::parseLogs() {
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

void Logs::uploadLogsToComputer() {

}

QString Logs::logsToString() {
    return QString("womp womp");
}
