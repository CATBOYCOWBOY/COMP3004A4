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
    // copy and paste logs.csv in this directory into the logs.csv file in the build folder
    this->sessionsList = parseLogs();

    // display any log history on startup
    for (int i = 0; i < this->sessionsList.size(); i++) {
        updateUi(i + 1, this->sessionsList[i]);
    }
}

LogsController::~LogsController() {}

QList<QStringList> LogsController::parseLogs() {
    QList<QStringList> sessionsData;
    // parse file for log history
    QFile logsCSV(QCoreApplication::applicationDirPath() + "/logs.csv");
    if (logsCSV.open(QIODevice::ReadWrite)) {
        QTextStream stream(&logsCSV);
        while (stream.atEnd() == false) {
            QString line = stream.readLine();
            QStringList data = line.split(",");
            sessionsData.append(data);
        }
    }
    logsCSV.close();    
    return sessionsData;
}

void LogsController::updateUi(int id, QStringList logData) {
    ui->sessionsList->insertItem(id, logsToString(id, logData[0], logData[1], logData[2], logData[3]));
}

QString LogsController::logsToString(int sessionId, QString startTime, QString startBaseline, QString endTime, QString endBaseline) {
    QString formattedString = QString(
        "-----------------SESSION ID: %1-----------------\n->Start Time: %2\n->Start Baseline: %3\n->End Time: %4\n->End Baseline: %5\n-------------------------------------------------------\n"
    ).arg(
        QString::number(sessionId),
        startTime,
        startBaseline,
        endTime,
        endBaseline
    );
    return formattedString;
}

void LogsController::writeLogsToComputer() {
    // write whatever is currently in logs.csv to data.csv
    QList<QStringList> currentSessionsData = parseLogs();
    QFile dataCSV(QCoreApplication::applicationDirPath() + "/data.csv");
    if (dataCSV.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream stream(&dataCSV);
        for (int i = 0; i < currentSessionsData.size(); i++) {
            stream << currentSessionsData[i][0] << "," << currentSessionsData[i][1] << "," << currentSessionsData[i][2] << "," << currentSessionsData[i][3] << Qt::endl;
        }
    }
    dataCSV.close();
}

void LogsController::writeLogsToDevice() {
    // write to logs.csv and save
    QFile logsCSV(QCoreApplication::applicationDirPath() + "/logs.csv");
    if (logsCSV.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream stream(&logsCSV);
        for (int i = 0; i < this->sessionsList.size(); i++) {
            stream << this->sessionsList[i][0] << "," << this->sessionsList[i][1] << "," << this->sessionsList[i][2] << "," << this->sessionsList[i][3] << Qt::endl;
        }
    }
    logsCSV.close();
}

// slots
void LogsController::addSessionToLogs(const QString& str) {
    // if a treatment has been completed add it to the logs
    QStringList newData = str.split(",");
    this->sessionsList.append(newData);
    updateUi(this->sessionsList.size(), newData);
    writeLogsToDevice();
}

void LogsController::onUpButtonPressed(int i) {
    if (controllerId != i) { return; }
    ui->sessionsList->verticalScrollBar()->triggerAction(QAbstractSlider::SliderPageStepSub);
}

void LogsController::onDownButtonPressed(int i) {
    if (controllerId != i) { return; }
    ui->sessionsList->verticalScrollBar()->triggerAction(QAbstractSlider::SliderPageStepAdd);
}

void LogsController::onPlayButtonPressed(int i) {
    if (controllerId != i) { return; }
    writeLogsToComputer();
}

void LogsController::onStopButtonPressed(int i) {
    if (controllerId != i) { return; }
}

void LogsController::onPauseButtonPressed(int i) {
    if (controllerId != i) { return; }
}

