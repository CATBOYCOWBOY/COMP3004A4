#ifndef SESSION_H
#define SESSION_H

#include <QString>

class Session {
    public:
        // constructors
        Session();

        // destructor
        ~Session();

        // getters and setters
        QString getDateTime();
        int getStartBaseline();
        int getEndBaseline();

    private: 
        int id;
        QString datetime;
        int startBaseline;
        int endBaseline;
};

#endif 
