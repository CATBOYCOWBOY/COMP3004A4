#ifndef LOGS_H
#define LOGS_H

#include "Session.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Logs {
    public:
        // constructor
        Logs();

        // destructor
        ~Logs();

        // member functions
        void uploadLogsToComputer();
        QString toString();
        // <vector>Session parseLogs(string fileName);

    private:
        // <vector>Session sessions;
        int numSessions;
};

#endif // LOGS_H
