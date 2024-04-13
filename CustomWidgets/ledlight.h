#ifndef LEDLIGHT_H
#define LEDLIGHT_H

#include <QWidget>
#include <QTimer>

class LedLight: public QWidget {
    Q_OBJECT
  public:
    LedLight(QColor color, QWidget *parent = 0);
    void setState(bool state);
    void setOnColor(QColor onColor);
    void setOffColor(QColor offColor);
    void setOnPattern(Qt::BrushStyle onPattern);
    void setOffPattern(Qt::BrushStyle offPattern);
    void setLedSize(int size);
    void toggle();

  public slots:
    void startFlashing();
    void stopFlashing();
    void turnOn();
    void shutOff();

  protected:
    void paintEvent(QPaintEvent *);
  private:
    bool lit;
    QColor ledOnColor;
    QColor ledOffColor;
    Qt::BrushStyle ledOnPattern;
    Qt::BrushStyle ledOffPattern;
    int ledSize;
    QTimer *flashTimer;
};

#endif

