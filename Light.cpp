#include "Light.h"

Light::Light(QString color, QString name) {
    this->color = color;
    this->name = name;
    this->isOn = false;
}

Light::~Light() {}

