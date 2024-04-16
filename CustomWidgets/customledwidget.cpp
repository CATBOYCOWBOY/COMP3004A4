#include "customledwidget.h"
#include "constants.h"
#include <QPainter>

CustomLedWidget::CustomLedWidget(QWidget *parent, bool isFlashingLight, QColor color)
    : QWidget{parent}, on(false), isFlashingLight(isFlashingLight), color(color)
{
  timer = new QTimer();
  mutex = new QMutex();
  connect(timer, &QTimer::timeout, this, &CustomLedWidget::flash, Qt::DirectConnection);
}

CustomLedWidget::~CustomLedWidget()
{
  if (isFlashingLight)
  {
    delete timer;
  }
}

void CustomLedWidget::turnOn(bool isFlashing)
{
  if (on) {
    return;
  }
  isFlashingLight = isFlashing;
  on = true;
  isLightActive = true;
  if (isFlashingLight)
  {
    timer->start(LED_FLASH_INTERVAL);

    return;
  }
  timer->stop();
  repaint();
}

void CustomLedWidget::turnOff()
{
  on = false;
  isLightActive = false;
  if (isFlashingLight)
  {
    timer->stop();
  }
  repaint();
}

void CustomLedWidget::setColor(QColor newColor)
{
  color = newColor;
}

void CustomLedWidget::flash()
{
  mutex->lock();
  isLightActive = !isLightActive;
  mutex->unlock();
  repaint();
}

void CustomLedWidget::paintEvent(QPaintEvent *)
{
  QPainter p(this);
  if (isLightActive) {
    p.setBrush(QBrush(color, Qt::SolidPattern));
  } else {
    p.setBrush(QBrush(Qt::gray, Qt::SolidPattern));
  }
  mutex->lock();
  p.drawEllipse(0, 0, LED_DIAMETER, LED_DIAMETER);
  mutex->unlock();
}
