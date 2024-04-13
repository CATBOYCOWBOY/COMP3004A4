#include "LogsController.h"
#include <QDebug>

LogsController::LogsController(QObject *parent, Ui::MainWindow *mw, int i) :
    ui(mw),
    controllerId(i)
{

    if (!parent || !mw || i < 0) {
        exit(-1);
    }

    ui->primaryTabs->setTabText(LOGS_TAB_INDEX, LOGS_TAB_TEXT);

    parseLogs();
    updateUi();
    writeLogsToDisk();
}

LogsController::~LogsController() {}

void LogsController::parseLogs() {
    // parse file for log history
    QFile CSVFile(QCoreApplication::applicationDirPath() + "/logs.csv");
    if (CSVFile.open(QIODevice::ReadWrite)) {
        QTextStream stream(&CSVFile);
        // skip first line
        stream.readLine();
        while (stream.atEnd() == false) {
            QString line = stream.readLine();
            QStringList data = line.split(",");
            this->sessionsList.append(data);
        }
    }
    CSVFile.close();
}

void addSession() {

}

void LogsController::updateUi() {
    for (int i = 0; i < this->sessionsList.size(); i++) {
        ui->sessionsList->insertItem(
            i, 
            logsToString(
                i+1,
                sessionsList[i][0], 
                sessionsList[i][1],
                sessionsList[i][2],
                sessionsList[i][3]
            )
        );
    }
}

QString LogsController::logsToString(int sessionId, QString startTime, QString endTime, QString startBaseline, QString endBaseline) {
    QString formattedString = QString(
        "-----------------SESSION ID: %1-----------------\n->Start Time: %2\n->End Time: %3\n->Start Baseline: %4\n->End Baseline: %5\n-----------------------------------------------------\n"
    ).arg(
        QString::number(sessionId),
        startTime,
        endTime,
        startBaseline,
        endBaseline
    );
    return formattedString;
}

void LogsController::writeLogsToDisk() {
    // add session to datalist to test
    QString line = "womp,womp,womp,womp";
    QStringList data = line.split(",");
    this->sessionsList.append(data);
    // write to logs.csv and save
    QFile CSVFile(QCoreApplication::applicationDirPath() + "/logs.csv");
    if (CSVFile.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream stream(&CSVFile);
        for (int i = 0; i < this->sessionsList.size(); i++) {
            stream << this->sessionsList[i][0] << "," << this->sessionsList[i][1] << "," << this->sessionsList[i][2] << "," << this->sessionsList[i][3] << Qt::endl;
        }
    }
    CSVFile.close();

}

void LogsController::uploadLogsToComputer() {

}

// slots
void LogsController::onUpButtonPressed(int i) {
    if (controllerId != i) { return; }
    qDebug() << "up was pressed" << Qt::endl;
}

void LogsController::onDownButtonPressed(int i) {
    if (controllerId != i) { return; }
    qDebug() << "down was pressed" << Qt::endl;
}

void LogsController::onPlayButtonPressed(int i) {
    if (controllerId != i) { return; }
    qDebug() << "play was pressed" << Qt::endl;
}

void LogsController::onStopButtonPressed(int i) {
    if (controllerId != i) { return; }
    qDebug() << "stop was pressed" << Qt::endl;
}

void LogsController::onPauseButtonPressed(int i) {
    if (controllerId != i) { return; }
    qDebug() << "pause was pressed" << Qt::endl;
}

// signals
//void LogsController::uploadLogsToComputerButtonClicked() {
//    uploadLogsToComputer();
//}


