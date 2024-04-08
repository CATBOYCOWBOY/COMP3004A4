#include "eegsensor.h"
#include "constants.h"
#include <QDebug>
#include <QRandomGenerator>

EEGSensor::EEGSensor(QObject *parent, int i):
  QObject{parent},
  sensorNumber(i),
  alphaDist((ALPHA_MAX - ALPHA_MIN)/2, ALPHA_FREQ_STDEV),
  betaDist((BETA_MAX - BETA_MIN)/2, BETA_FREQ_STDEV),
  thetaDist((THETA_MAX - THETA_MIN)/2, THETA_FREQ_STDEV),
  deltaDist((DELTA_MAX - DELTA_MIN)/2, DELTA_FREQ_STDEV),
  currentYSeries(NUM_SAMPLES),
  sensorMutex(new QMutex())
{
}

EEGSensor::~EEGSensor()
{
  delete sensorMutex;
}

const QVector<double> EEGSensor::getCurrentSeries()
{
  for (int i = 0; i < NUM_SAMPLES; i++)
  {
    currentYSeries[i] =
        alphaAmp * sin(alphaFreq * TWO_PI * i * (INTERVAL_END / NUM_SAMPLES)) + // want to get wave w at ith sample (e/g w(0.01), w(0.02),etc
        betaAmp * sin(betaFreq * TWO_PI * i * (INTERVAL_END / NUM_SAMPLES)) +
        thetaAmp * sin(thetaFreq * TWO_PI * i * (INTERVAL_END / NUM_SAMPLES)) +
        deltaAmp * sin(deltaFreq * TWO_PI * i * (INTERVAL_END / NUM_SAMPLES)) +
        OFFSET_FREQ_STRENGTH * sin((OFFSET_FREQ_VALUE + getBaselineFreq()) * TWO_PI * i * (INTERVAL_END/NUM_SAMPLES));
  }
  return currentYSeries;
}

void EEGSensor::run()
{
  while (isSensorOperating)
  {
    if (isTreatmentOperating)
    {
        runTreatment();
    }
    QThread::msleep(500);
  }
  emit shutOff();
}

void EEGSensor::onBatteryLow()
{
  sensorMutex->lock();
  isBatteryLow = true;
  sensorMutex->unlock();
}

void EEGSensor::onDisconnect()
{
  sensorMutex->lock();
  isConnectionsBroken = true;
  sensorMutex->unlock();
}

void EEGSensor::onTreatmentStart()
{
  sensorMutex->lock();
  isTreatmentOperating = true;
  sensorMutex->unlock();
}

void EEGSensor::onTreatmentPause()
{
  sensorMutex->lock();
  isTreatmentPaused = true;
  sensorMutex->unlock();
}

void EEGSensor::onTreatmentUnpaused()
{
  sensorMutex->lock();
  isTreatmentPaused = false;
  sensorMutex->unlock();
}

void EEGSensor::onTreatmentStopped()
{
  sensorMutex->lock();
  isTreatmentPaused = false;
  isTreatmentOperating = false;
  sensorMutex->unlock();
}

void EEGSensor::onBatteryReset()
{
  sensorMutex->lock();
  isBatteryLow = false;
  sensorMutex->unlock();
}

void EEGSensor::onConnectionReset()
{
  sensorMutex->lock();
  isConnectionsBroken = false;
  sensorMutex->unlock();
}

void EEGSensor::onShutOff()
{
  isSensorOperating = false;
  isTreatmentOperating = false;
}

void EEGSensor::runTreatment()
{
  offsetsApplied = 0;
  initializeValues();
  double baseline = getBaselineFreq();
  emit treatmentStarted(baseline);

  // 4 rounds of treatment, 5 second baseline 1 second offset application
  // should apply 80 hz offset frequency at 200 microvolts by the end
  for (int i = 0; i < NUM_FEEDBACK_ROUNDS; i++)
  {
    if (!isSensorOperating || !isTreatmentOperating)
    {
      return;
    }

    // 5 seconds, establish baseline
    for (int j = 0; j < 50; j++)
    {
      QThread::msleep(9);
      errorHandler();
    }

    // 1 second, give treatment
    for (int j = 0; j < NUM_OFFSETS; j++)
    {
      errorHandler();
      QThread::msleep(64); // very close to 1/16 second
      offsetsApplied += 1;
      emit frequencyUpdated(sensorNumber);
    }

    QThread::msleep(100);
  }

  baseline = getBaselineFreq();
  emit treatmentEnded(baseline);
  isTreatmentOperating = false;
  offsetsApplied = 0;
}

void EEGSensor::errorHandler()
{
  // error handler event loop
  int msElapsed = 0;

  while((isConnectionsBroken || isBatteryLow) && isSensorOperating)
  {
    msElapsed += 10;
    if (msElapsed >= FIVE_MINUTES_MS || !isSensorOperating)
    {
      emit fiveMinutesDisconnected();
    }
    QThread::msleep(10);
  }
}

void EEGSensor::initializeValues()
{
  // Initializer for randomly generated freq, amplitude values for brainwave bands on ctor and treatment cycle
  // Amplitude "amp" values are generated off of a "normal" range of 20-200 microvolts
  // in theory, max amplitude for combined waveform 800 microvolts
  // don't touch the casting
  // alphaFreq = getNormalValueInRange(alphaDist, rand, ALPHA_MIN, ALPHA_MAX);

  // generating frequencies as uniform distribution for efficiency - distribution was not specified
  alphaFreq = ALPHA_MIN + QRandomGenerator::global()->generateDouble() * (ALPHA_MAX - ALPHA_MIN);
  alphaAmp = 20 + QRandomGenerator::global()->generateDouble() * 180;

  betaFreq = BETA_MIN + QRandomGenerator::global()->generateDouble() *  (BETA_MAX - BETA_MIN);
  betaAmp = 20 + QRandomGenerator::global()->generateDouble() * 180;

  thetaFreq = THETA_MIN + QRandomGenerator::global()->generateDouble() * (THETA_MAX - THETA_MIN);
  thetaAmp = 20 + QRandomGenerator::global()->generateDouble() * 180;

  deltaFreq = DELTA_MIN + QRandomGenerator::global()->generateDouble() * (DELTA_MAX - DELTA_MIN);
  deltaAmp = 20 + QRandomGenerator::global()->generateDouble() * 180;
}

double EEGSensor::getBaselineFreq() const
{
  return (alphaFreq * alphaAmp +
          betaFreq * betaAmp +
          thetaFreq * thetaAmp +
          deltaFreq * deltaAmp +
          OFFSET_FREQ_VALUE * offsetsApplied * OFFSET_FREQ_STRENGTH)/
      (alphaAmp + betaAmp + thetaAmp + deltaAmp + offsetsApplied * OFFSET_FREQ_STRENGTH);
}
