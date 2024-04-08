#ifndef EEGSENSOR_H
#define EEGSENSOR_H

#include <QObject>
#include <QVector>
#include <QMutex>
#include <random>
#include <QThread>

class EEGSensor : public QObject
{
  Q_OBJECT
public:
  explicit EEGSensor(QObject *parent = nullptr, int i = -1);

  ~EEGSensor();

  const QVector<double> getCurrentSeries();
signals:
  void shutOff();
  void treatmentStarted(double);
  void treatmentEnded(double);
  void frequencyUpdated(int);

  void fiveMinutesDisconnected();

public slots:
  void run();
  void onBatteryLow();
  void onDisconnect();
  void onTreatmentStart();
  void onTreatmentPause();
  void onTreatmentUnpaused();
  void onTreatmentStopped();

  void onBatteryReset();
  void onConnectionReset();
  void onShutOff();

private:
  int sensorNumber;
  bool isSensorOperating = true;
  bool isTreatmentOperating = false;
  bool isTreatmentPaused = false;
  bool isBatteryLow = false;
  bool isConnectionsBroken = false;

  float alphaFreq = 0;
  float alphaAmp = 0;

  float betaFreq = 0;
  float betaAmp = 0;

  float thetaFreq = 0;
  float thetaAmp = 0;

  float deltaFreq = 0;
  float deltaAmp = 0;

  // counting offsets of 5 mhz, as well as
  int offsetsApplied = 0;

  std::normal_distribution<float> alphaDist;
  std::normal_distribution<float> betaDist;
  std::normal_distribution<float> thetaDist;
  std::normal_distribution<float> deltaDist;

  std::default_random_engine rand;

  std::random_device randomGenerator;
  double baselineFreq; // calculated based on current alpha, beta, theta, delta values

  QVector<double> currentYSeries;
  QMutex* sensorMutex;

  void runTreatment();
  void errorHandler();
  void initializeValues();
  double getBaselineFreq() const;
};

#endif // EEGSENSOR_H
