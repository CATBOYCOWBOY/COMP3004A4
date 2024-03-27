#include "Button.h"

Button::Button(QString name) {
    this->name = name;
    this->isPressed = false;
}

Button::~Button() {}

QString Button::getName() { return this->name; }

bool Button::getIsPressed() { return this->isPressed; }

void Button::setIsPressed(bool pressed) { this->isPressed = pressed; }
