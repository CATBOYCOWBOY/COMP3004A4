#include "Session.h"
#include <QString>

Session::Session() {}

Session::Session(int id, QString startTime, QString endTime, int startBaseline, int endBaseline) {
    this->id = id;
    this->startTime = startTime;
    this->endTime = endTime;
    this->startBaseline = startBaseline;
    this->endBaseline = endBaseline;
}

Session::~Session() {}

QString Session::sessionToString() {
    QString formattedString = QString(
        "SESSION ID: %1\n->Start Time: %2\n->End Time: %3\n->Start Baseline: %4\n->EndBaseline: %5"
    ).arg(
        QString::number(this->id), 
        this->startTime, 
        this->endTime, 
        QString::number(this->startBaseline), 
        QString::number(this->endBaseline)
    );
    return formattedString;
}

QString Session::getStartTime() { return this->startTime; }

QString Session::getEndTime() { return this->endTime; }

int Session::getStartBaseline() { return this->startBaseline; }

int Session::getEndBaseline() { reutrn this->endBaseline; }


