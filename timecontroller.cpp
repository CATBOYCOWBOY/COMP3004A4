#include "timecontroller.h"
#include <QDebug>

TimeController::TimeController(QObject* parent, Ui::MainWindow *ui, int i) : mw(ui), controllerId(i)
{
    this->parent = parent;
    mw = ui;
    timeUpdater = new TimeUpdater();
    qthread = new QThread();
    timeUpdater->moveToThread(qthread);
    connect(qthread, &QThread::started, timeUpdater, &TimeUpdater::run);
    connect(timeUpdater, &TimeUpdater::shutOff, qthread, &QThread::quit, Qt::DirectConnection);
    connect(qthread, &QThread::finished, timeUpdater, &TimeUpdater::deleteLater);
    connect(timeUpdater, &TimeUpdater::updateTime, this, &TimeController::onDeviceTimeUpdate, Qt::DirectConnection);
    connect(this, &TimeController::shutOff, timeUpdater, &TimeUpdater::onShutOff, Qt::DirectConnection);
    qthread->start();
    viewTime = true;
}

TimeController::~TimeController()
{
    emit shutOff();
}

QString TimeController::getTime()
{
    return (currentDateTime->addSecs(secsDelay)).toString();
}

void TimeController::onDeviceTimeUpdate()
{
    qDebug() << "onDeviceTimeUpdate";
    *currentDateTime = QDateTime::currentDateTime();
    qDebug() << getTime();
    if(viewTime == true){updateTimeDisplay();}
}

void TimeController::updateTimeDisplay()
{
    mw->yearDisplay->display(currentDateTime->addSecs(secsDelay).date().year());
    mw->monthDisplay->display(currentDateTime->addSecs(secsDelay).date().month());
    mw->dayDisplay->display(currentDateTime->addSecs(secsDelay).date().day());
    mw->hourDisplay->display(currentDateTime->addSecs(secsDelay).time().hour());
    mw->minuteDisplay->display(currentDateTime->addSecs(secsDelay).time().minute());
}

void TimeController::setDateTime() //update the secondsDelay value
{
    tempDate = QDate(tempYear, tempMonth, tempDay);
    tempTime = QTime(tempHour, tempMinute, 0, 0);
    tempDateTime = QDateTime(tempDate, tempTime);
    secsDelay = currentDateTime->secsTo(tempDateTime);
}

void TimeController::updateTempVals() //update tempVals to set them via user interation
{
    tempDateTime = currentDateTime->addSecs(secsDelay);
    tempYear = tempDateTime.date().year();
    tempMonth = tempDateTime.date().month();
    tempDay = tempDateTime.date().day();
    tempHour = tempDateTime.time().hour();
    tempMinute = tempDateTime.time().minute();
}

void TimeController::onPlayButtonPressed(int i)
{
    if (controllerId != i)
        {
            return;
        }
    //go forward in menu
    if(viewTime == false){
        if(setYear == true){
            setYear = false;
            setMonth = true;
            mw->yearDisplay->setLineWidth(1);
            mw->monthDisplay->setLineWidth(5);
        }
        else if(setMonth == true){
            setMonth = false;
            setDay = true;
            mw->monthDisplay->setLineWidth(1);
            mw->dayDisplay->setLineWidth(5);
        }
        else if(setDay == true){
            setDay = false;
            setHour = true;
            mw->dayDisplay->setLineWidth(1);
            mw->hourDisplay->setLineWidth(5);
        }
        else if(setHour == true){
            setHour = false;
            setMinute = true;
            mw->hourDisplay->setLineWidth(1);
            mw->minuteDisplay->setLineWidth(5);
        }
        else{
            //reset perms
            setMinute = false;
            mw->minuteDisplay->setLineWidth(1);
            setDateTime();
            updateTimeDisplay();
            viewTime = true;
        }
    }
}

void TimeController::onPauseButtonPressed(int i)
{
    if (controllerId != i)
        {
            return;
        }
    //go back in menu
    if(viewTime == false){
        if(setMinute == true){
            setMinute = false;
            setHour = true;
            mw->minuteDisplay->setLineWidth(1);
            mw->hourDisplay->setLineWidth(5);
        }
        else if(setHour == true){
            setHour = false;
            setDay = true;
            mw->hourDisplay->setLineWidth(1);
            mw->dayDisplay->setLineWidth(5);
        }
        else if(setDay == true){
            setDay = false;
            setMonth = true;
            mw->dayDisplay->setLineWidth(1);
            mw->monthDisplay->setLineWidth(5);
        }
        else if(setMonth == true){
            setMonth = false;
            setYear = true;
            mw->monthDisplay->setLineWidth(1);
            mw->yearDisplay->setLineWidth(5);
        }
    }
}

void TimeController::onStopButtonPressed(int i)
{
    if (controllerId != i)
        {
            return;
        }
    if(viewTime == true){
        //toggle timeView
        updateTempVals();
        viewTime = false;
        setYear = true;
        mw->yearDisplay->setLineWidth(5);
        qDebug() << "setTime";
    }
    else{
        updateTimeDisplay();
        setYear = false;
        setMonth = false;
        setDay = false;
        setHour = false;
        setMinute = false;
        mw->yearDisplay->setLineWidth(1);
        mw->monthDisplay->setLineWidth(1);
        mw->dayDisplay->setLineWidth(1);
        mw->hourDisplay->setLineWidth(1);
        mw->minuteDisplay->setLineWidth(1);
        viewTime = true;
        qDebug() << "viewTime";
    }

}

void TimeController::onUpButtonPressed(int i)
{
    if (controllerId != i)
        {
            return;
        }
    if(viewTime == false){
        if(setYear == true){
            tempYear++;
            if(tempYear > 9999){tempYear = 0;}
            else if(tempYear % 4 == 0 && tempYear % 100 != 0 && tempMonth == 2 && tempDay > 28){
                tempDay = 28;
                mw->dayDisplay->display(tempDay);
            }
            else if(tempYear % 100 == 0 && tempMonth == 2 && tempDay > 29){
                tempDay = 29;
                mw->dayDisplay->display(tempDay);
            }
            else if(tempYear % 4 == 0 && tempMonth == 2 && tempDay > 28){
                tempDay = 28;
                mw->dayDisplay->display(tempDay);
            }
            //if year changed to leap, update day value
            mw->yearDisplay->display(tempYear);
        }
        else if(setMonth == true){
            tempMonth++;
            if(tempMonth > 12){tempMonth = 1;}
            else if(tempMonth == 2 && tempDay >= 28 && tempYear % 4 != 0){
                tempDay = 28;
                mw->dayDisplay->display(tempDay);
            }
            else if(tempMonth == 2 && tempDay >= 29 && tempYear % 4 == 0){
                tempDay = 29;
                mw->dayDisplay->display(tempDay);
            }
            if(tempMonth == 2 && tempDay > 28){
                tempDay = 28;
                mw->dayDisplay->display(tempDay);
            }
            //change date
            mw->monthDisplay->display(tempMonth);

        }
        else if(setDay == true){
            //check that day is a valid day
            tempDay++;
            if(tempMonth == 4 || tempMonth == 6 || tempMonth == 9 || tempMonth == 11){
                if(tempDay == 31){tempDay = 1;}
            }
            else if(tempMonth == 2){
                if(tempYear % 4 == 0 && tempYear % 100 != 0){
                    if(tempDay == 30){tempDay = 1;}
                }
                else{
                    if(tempDay == 29){tempDay = 1;}
                }
            }
            else{
                if(tempDay == 32){tempDay = 1;}
            }
            mw->dayDisplay->display(tempDay);
        }
        else if(setHour == true){
            tempHour++;
            if(tempHour == 24){
                tempHour = 0;
            }
            mw->hourDisplay->display(tempHour);
        }
        else if(setMinute == true){
            tempMinute++;
            if(tempMinute == 60){
                tempMinute = 0;
            }
            mw->minuteDisplay->display(tempMinute);
        }
    }
}

void TimeController::onDownButtonPressed(int i)
{
    if (controllerId != i)
        {
            return;
        }
    if(viewTime == false){
        if(setYear == true){
            tempYear--;
            if(tempYear < 0){tempYear = 9999;}
            else if(tempYear % 4 == 0 && tempMonth == 2 && tempDay > 28){
                tempDay = 28;
                mw->dayDisplay->display(tempDay);
            }
            //if year changed to leap, update day value
            mw->yearDisplay->display(tempYear);
        }
        else if(setMonth == true){
            tempMonth--;
            if(tempMonth == 0){tempMonth = 12;}
            if(tempMonth == 2 && tempDay > 28){
                tempDay = 28;
                mw->dayDisplay->display(tempDay);
            }
            //change date
            mw->monthDisplay->display(tempMonth);

        }
        else if(setDay == true){
            //check that day is a valid day
            tempDay--;
            if(tempMonth == 4 || tempMonth == 6 || tempMonth == 9 || tempMonth == 11){
                if(tempDay == 0){tempDay = 31;}
            }
            else if(tempMonth == 2){
                if(tempYear % 4 == 0 && tempYear % 100 != 0){
                    if(tempDay == 0){tempDay = 29;}
                }
                else{
                    if(tempDay == 0){tempDay = 28;}
                }
            }
            else{
                if(tempDay == 0){tempDay = 31;}
            }
            mw->dayDisplay->display(tempDay);
        }
        else if(setHour == true){
            tempHour--;
            if(tempHour == -1){
                tempHour = 23;
            }
            mw->hourDisplay->display(tempHour);
        }
        else if(setMinute == true){
            tempMinute--;
            if(tempMinute == -1){
                tempMinute = 59;
            }
            mw->minuteDisplay->display(tempMinute);
        }
    }

}

/*
    #PauseButton
    #go back in menu
    if(viewTime == True){
        qDebug() << "RAHHHHHHHHH"
    }
    else{
        if(setMinute == True){
            setMinute = False;
            setHour = True;
        }
        else if(setHour == True){
            setHour = False;
            setDay = True;
        }
        else if(setDay == True){
            setDay = False;
            setMonth = True;
        }
        else if(setMonth == True){
            setMonth = False;
            setYear = True;
        }
    }

    #PlayButton
    #go forward in menu
    if(viewTime == True){
        qDebug() << "RAHHHHHHHHH"
    }
    else{
        if(setYear == True){
            setYear = False;
            setMonth = True;
        }
        else if(setMonth == True){
            setMonth = False;
            setDay = True;
        }
        else if(setDay == True){
            setDay = False;
            setHour = True;
        }
        else if(setHour == True){
            setHour = False;
            setMinute = True;
        }
        else{
            //reset perms
            setMinute = False;
            setDateTime();
            updateTimeDisplay();
            viewTime = True;
        }
    }


    # UpButton
    if(viewTime == False){
        if(setYear == True){
            tempYear++;
            if(tempYear > 9999){tempYear = 0};
            else if(tempYear % 4 == 0 && tempMonth == 2 && tempDay > 28){
                tempDay = 28;
                mw->dayDisplay->display(tempDay);
            }
            //if year changed to leap, update day value
            mw->yearDisplay->display(tempYear);
        }
        else if(setMonth == True){
            tempMonth++;
            if(tempMonth > 12){tempMonth = 1};
            if(tempMonth == 2 && tempDay > 28){
                tempDay = 28;
                mw->dayDisplay->display(tempDay);
            }
            //change date
            mw->monthDisplay->display(tempMonth);

        }
        else if(setDay == True){
            //check that day is a valid day
            tempDay++;
            if(tempMonth == 4 || tempMonth == 6 || tempMonth == 9 || tempMonth == 11){
                if(tempDay == 31){tempDay = 1};
            }
            else if(tempMonth == 2){
                if(tempYear % 4 == 0 && tempYear % 100 != 0){
                    if(tempDay == 30){tempDay = 1};
                }
                else{
                    if(tempDay == 29){tempDay = 1};
                }
            }
            else{
                if(tempDay == 32){tempDay = 1};
            }
            mw->dayDisplay->display(tempDay);
        }
        else if(setHour == True){
            tempHour++;
            if(tempHour == 24){
                tempHour == 0;
            }
            mw->hourDisplay->display(tempHour);
        }
        else if(setMinute == True){
            tempMinute++;
            if(tempMinute == 60){
                tempMinute = 0
            }
            mw->minuteDisplay->display(tempMinute);
        }
    }

    # DownButton
    if(viewTime == False){
        if(setYear == True){
            tempYear--;
            if(tempYear < 0){tempYear = 9999};
            else if(tempYear % 4 == 0 && tempMonth == 2 && tempDay > 28){
                tempDay = 28;
                mw->dayDisplay->display(tempDay);
            }
            //if year changed to leap, update day value
            mw->yearDisplay->display(tempYear);
        }
        else if(setMonth == True){
            tempMonth--;
            if(tempMonth = 0){tempMonth = 12};
            if(tempMonth == 2 && tempDay > 28){
                tempDay = 28;
                mw->dayDisplay->display(tempDay);
            }
            //change date
            mw->monthDisplay->display(tempMonth);

        }
        else if(setDay == True){
            //check that day is a valid day
            tempDay--;
            if(tempMonth == 4 || tempMonth == 6 || tempMonth == 9 || tempMonth == 11){
                if(tempDay == 0){tempDay = 31};
            }
            else if(tempMonth == 2){
                if(tempYear % 4 == 0 && tempYear % 100 != 0){
                    if(tempDay == 0){tempDay = 30};
                }
                else{
                    if(tempDay == 0){tempDay = 29};
                }
            }
            else{
                if(tempDay == 0){tempDay = 31};
            }
            mw->dayDisplay->display(tempDay);
        }
        else if(setHour == True){
            tempHour--;
            if(tempHour == -1){
                tempHour == 23;
            }
            mw->hourDisplay->display(tempHour);
        }
        else if(setMinute == True){
            tempMinute--;
            if(tempMinute == -1){
                tempMinute = 59
            }
            mw->minuteDisplay->display(tempMinute);
        }
    }


*/



