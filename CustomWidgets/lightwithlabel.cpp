#include "lightwithlabel.h"

LightWithLabel::LightWithLabel(QWidget *parent, std::string text, QColor color): QWidget{parent}
{
  layout = new QVBoxLayout(this);
  light = new CustomLedWidget(this, false, color);
  label = new QLabel(this);
  label->setText(QString::fromStdString(text));
  layout->insertWidget(0, label);
  layout->insertWidget(1, light);
  update();
}

void LightWithLabel::solidOn()
{
  light->turnOn(false);
}

void LightWithLabel::flashOn()
{
  light->turnOn(true);
}

void LightWithLabel::turnOff()
{
  light->turnOff();
}

void LightWithLabel::setColor(const QColor color)
{
  light->setColor(color);
}
