#include "LogsController.h"
#include <QDebug>

LogsController::LogsController(QObject *parent, Ui::MainWindow *mw, int i) :
    NeuresetController{parent},
    ui(mw),
    controllerId(i) 
{
    ui->primaryTabs->setTabText(LOGS_TAB_INDEX, LOGS_TAB_TEXT);
    ui->logsScrollArea->setWidget(ui->sessionsList);
}

LogsController::~LogsController() {}

void LogsController::parseLogs() {
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

    // try printing it in the list view


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

void LogsController::uploadLogsToComputer() {

}

QString LogsController::logsToString() {
    return QString("womp womp");
}

// signals
void LogsController::onUpButtonPressed(int i) {
    if (controllerId != i) return;
    qDebug() << "up was pressed" << Qt::endl;
}

void LogsController::onDownButonPressed(int i) {
    if (controllerId != i) return;
    qDebug() << "down was pressed" << Qt::endl;
}

void LogsController::onPlayButtonPressed(int i) {
    if (controllerId != i) return;
    qDebug() << "play was pressed" << Qt::endl;
}

void LogsController::onStopButtonPressed(int i) {
    if (controllerId != i) return;
    qDebug() << "stop was pressed" << Qt::endl;
}

void LogsController::onPauseButonPressed(int i) {
    if (controllerId != i) return;
    qDebug() << "pause was pressed" << Qt::endl;
}

// slots
//void LogsController::uploadLogsToComputerButtonClicked() {
//    uploadLogsToComputer();
//}


