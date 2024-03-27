#ifndef BUTTON_H
#define BUTTON_H

#include <QString>

class Button {
    public:
        // constructor
        Button(QString name);

        // destructor
        ~Button();

        // getters | setters
        QString getName();
        bool getIsPressed();
        void setIsPressed(bool);

    private:
        QString name;
        bool isPressed;
};
#endif
