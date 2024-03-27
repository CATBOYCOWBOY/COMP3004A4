#ifndef LIGHT_H
#define LIGHT_H

#include <QString>

class Light {
    public: 
        // constructor
        Light(QString color, QString name);

        // destructor 
        ~Light();
 
    private:
        QString color;
        QString name;
        bool isOn;

};
#endif
