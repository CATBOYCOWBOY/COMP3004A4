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
    parseLogs();
}

LogsController::~LogsController() {}

void LogsController::parseLogs() {
    // parse file for log history
    QFile CSVFile(QCoreApplication::applicationDirPath() + "/logs.csv");
    if (CSVFile.open(QIODevice::ReadWrite)) {
        QTextStream stream(&CSVFile);
        while (stream.atEnd() == false) {
            QString line = stream.readLine();
            QStringList data = line.split(",");
            this->sessionsList.append(data);
        }
    }
    CSVFile.close();

    // display any log history on startup
    for (int i = 0; i < this->sessionsList.size(); i++) {
        updateUi(i + 1, this->sessionsList[i]);
    }
}

void LogsController::updateUi(int id, QStringList logData) {
    ui->sessionsList->insertItem(id, logsToString(id, logData[0], logData[1], logData[2], logData[3]));
}

QString LogsController::logsToString(int sessionId, QString startTime, QString endTime, QString startBaseline, QString endBaseline) {
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

void LogsController::writeLogsToDisk() {
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

// slots
void LogsController::addSessionToLogs(const QString& str) {
    // if a treatment has been completed add it to the logs
    qDebug() << "logs received signal of completed treatment" << Qt::endl;
    QStringList newData = str.split(",");
    this->sessionsList.append(newData);
    updateUi(this->sessionsList.size(), newData);
}

void LogsController::onUpButtonPressed(int i) {
    if (controllerId != i) { return; }
    ui->sessionsList->verticalScrollBar()->triggerAction(QAbstractSlider::SliderPageStepSub);
    qDebug() << "up was pressed" << Qt::endl;
}

void LogsController::onDownButtonPressed(int i) {
    if (controllerId != i) { return; }
    ui->sessionsList->verticalScrollBar()->triggerAction(QAbstractSlider::SliderPageStepAdd);
    qDebug() << "down was pressed" << Qt::endl;
}

void LogsController::onPlayButtonPressed(int i) {
    if (controllerId != i) { return; }
    writeLogsToDisk();
    emit uploadLogsToComputerButtonClicked();
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

