#include "Logs.h"

Logs::Logs() {
    // look in logs.txt and parse data
    parseLogs();
}

Logs::~Logs() {}

QVector<Session> Logs::parseLogs() {
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

    // create and store session objects
    for (int i = 0; i < dataList.size(); i++) {
        Session *s = new Session(i+1, dataList[i][0], dataList[i][1], dataList[i][2].toInt(), dataList[i][3].toInt());
        this->sessions.append(&s);
    }

    // test print
    for (int i = 0; i < this->sessions.size(); i++) {
        qDebug() << this->sessions[i].sessionToString();
    }
 }

void Logs::uploadLogsToComputer() {

}

QString Logs::logsToString() {
    return QString("womp womp");
}