#ifndef DISPLAY_H
#define DISPLAY_H

#include "constants.h"
#include <QString>

class Display {
    public:
        // constructor
        Display();

        // destructor
        ~Display();

        // member functions
        void displayMenu();
        void displayDefaultView();
        void displayDateTime();
        void displaySessionLog();
        void displaySessionDate(int sessionId);

        // getters | setters
        QString getCurrentDateTime();

    private:
        QString currentDateTime;

};

#endif
