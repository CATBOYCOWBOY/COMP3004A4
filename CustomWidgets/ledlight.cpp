#include "ledlight.h"
#include <QPainter>

LedLight::LedLight(QColor color, QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(28, 28);
    lit = false;
    ledOnColor=color;
    ledOffColor=Qt::gray;
    ledOnPattern = Qt::SolidPattern;
    ledOffPattern = Qt::SolidPattern;
    ledSize=20;

    flashTimer = new QTimer(this);
    connect(flashTimer, &QTimer::timeout, this, &LedLight::toggle);
}

void LedLight::paintEvent(QPaintEvent *) {
  QPainter p(this);
  lit ?  p.setBrush(QBrush(ledOnColor, ledOnPattern)) : p.setBrush(QBrush(ledOffColor, ledOffPattern));
  p.drawEllipse(0,0,ledSize,ledSize);
}

void LedLight::setState(bool state)
{
    lit = state;
    update();
}

void LedLight::toggle()
{
    lit = ! lit;
    update();
}

void LedLight::shutOff() {
    lit = false;
    stopFlashing();
    update();
}

void LedLight::turnOn() {
    lit = true;
    update();
}

void LedLight::setOnColor(QColor onColor)
{
    ledOnColor=onColor;
    update();
}

void LedLight::setOffColor(QColor offColor)
{
    ledOffColor=offColor;
    update();
}

void LedLight::setOnPattern(Qt::BrushStyle onPattern)
{
    ledOnPattern=onPattern;
    update();
}

void LedLight::setOffPattern(Qt::BrushStyle offPattern)
{
    ledOffPattern=offPattern;
    update();
}

void LedLight::setLedSize(int size)
{
    ledSize=size;
    setFixedSize(size+10, size+10);
    update();
}

void LedLight::startFlashing()
{
    flashTimer->start(500);
}

void LedLight::stopFlashing()
{
    flashTimer->stop();
    setState(false);
    update();
}
