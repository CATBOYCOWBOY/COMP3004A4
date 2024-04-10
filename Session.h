#ifndef SESSION_H
#define SESSION_H

#include <QString>

class Session {
    public:
        // constructors
        Session();
        Session(int id, QString startTime, QString endTime, int startBaseline, int endBaseline);

        // destructor
        ~Session();

        // getters and setters
        QString getStartTime();
        QString getEndTime();
        int getStartBaseline();
        int getEndBaseline();
        QString sessionToString();

    private: 
        int id;
        QString startTime;
        QString endTime;
        int startBaseline;
        int endBaseline;
};

#endif 
