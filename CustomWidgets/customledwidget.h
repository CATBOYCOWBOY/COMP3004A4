#ifndef CUSTOMLEDWIDGET_H
#define CUSTOMLEDWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QMutex>

class CustomLedWidget : public QWidget
{
  Q_OBJECT
public:
  explicit CustomLedWidget(QWidget *parent = nullptr, bool isFlashingLight = false, QColor color = Qt::black);
  ~CustomLedWidget();

public slots:
  void paintEvent(QPaintEvent *);
  void turnOn(bool isFlashing = false);
  void turnOff();
  void flash();
  void setColor(QColor);

private:
  bool on;
  bool isFlashingLight;
  bool isLightActive;
  QColor color;
  QTimer *timer;
  QMutex *mutex;
};

#endif // CUSTOMLEDWIDGET_H
