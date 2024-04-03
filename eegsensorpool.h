#ifndef EEGSENSORPOOL_H
#define EEGSENSORPOOL_H

#include <QObject>

class EEGSensorPool : public QObject
{
  Q_OBJECT
public:
  explicit EEGSensorPool(QObject *parent = nullptr);

signals:

};

#endif // EEGSENSORPOOL_H
