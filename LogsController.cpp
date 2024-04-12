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
}

LogsController::~LogsController() {}

void LogsController::parseLogs() {
    // parse file
    QList<QStringList> dataList;

    QFile CSVFile(QCoreApplication::applicationDirPath() + "/logs.csv");
    if (CSVFile.open(QIODevice::ReadWrite)) {
        QTextStream stream(&CSVFile);
        // skip first line
        stream.readLine();
        while (stream.atEnd() == false) {
            QString line = stream.readLine();
            QStringList data = line.split(",");
            dataList.append(data);
        }
    }

    qDebug() << "dataList size: " << QString::number(dataList.length()) << Qt::endl;

    // try printing it in the list view
    for (int i = 0; i < dataList.size(); i++) {
        QString formattedString = QString(
            "-----------------SESSION ID: %1-----------------\n->Start Time: %2\n->End Time: %3\n->Start Baseline: %4\n->End Baseline: %5\n-----------------------------------------------------\n"
        ).arg(
            QString::number(i+1),
            dataList[i][0],
            dataList[i][1],
            dataList[i][2],
            dataList[i][3]
        );
        ui->sessionsList->insertItem(i, formattedString);
    }
}

void LogsController::uploadLogsToComputer() {

}

QString LogsController::logsToString() {
    return QString("womp womp");
}

// slots
void LogsController::onUpButtonPressed(int i) {
    if (controllerId != i) { return; }
    qDebug() << "up was pressed" << Qt::endl;
}

void LogsController::onDownButonPressed(int i) {
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

void LogsController::onPauseButonPressed(int i) {
    if (controllerId != i) { return; }
    qDebug() << "pause was pressed" << Qt::endl;
}

// signals
//void LogsController::uploadLogsToComputerButtonClicked() {
//    uploadLogsToComputer();
//}


