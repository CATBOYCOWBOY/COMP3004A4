#ifndef LIGHTWITHLABEL_H
#define LIGHTWITHLABEL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "customledwidget.h"

class LightWithLabel : public QWidget
{
  Q_OBJECT
  public:
  explicit LightWithLabel(QWidget *parent = nullptr, std::string text = "", QColor color = Qt::black);

  public slots:
    void solidOn();
    void flashOn();
    void turnOff();
    void setColor(const QColor color);

  private:
    QVBoxLayout *layout;
    CustomLedWidget *light;
    QLabel *label;
};

#endif // LIGHTWITHLABEL_H
