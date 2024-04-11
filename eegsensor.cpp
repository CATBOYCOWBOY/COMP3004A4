#include "eegsensor.h"
#include <QDebug>
#include <QRandomGenerator>

EEGSensor::EEGSensor(QObject *parent, int i):
  QObject{parent},
  sensorNumber(i),
  currentYSeries(NUM_SAMPLES),
  sensorMutex(new QMutex())
{
  for (int i = 0; i < NUM_FEEDBACK_ROUNDS; i++)
  {
    for (int j = 0; j < NUM_OFFSETS; j++)
    {
      feedbackFreqs[i][j] = 0;
    }
  }
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
        // since getBaseLineFreq() factors in the previously applied offsets, all we have to do is account for one most recent one
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
  resetSensorValues();
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
      if (!isTreatmentOperating)
      {
        resetSensorValues();
        return;
      }
      QThread::msleep(95);
      pauseHandler();
      errorHandler();
    }

    // 1 second, give treatment
    for (int j = 0; j < NUM_OFFSETS; j++)
    {
      if (!isTreatmentOperating)
      {
        resetSensorValues();
        return;
      }
      pauseHandler();
      errorHandler();
      QThread::msleep(64); // very close to 1/16 second
      offsetsApplied += 1;
      feedbackFreqs[i][j] = getBaselineFreq() + OFFSET_FREQ_VALUE;
      emit frequencyUpdated(sensorNumber);
    }
    emit cycleComplete();
  }

  for (int j = 0; j < 50; j++)
  {
    if (!isTreatmentOperating)
    {
      resetSensorValues();
      return;
    }
    QThread::msleep(95);
    pauseHandler();
    errorHandler();
  }

  baseline = getBaselineFreq();
  emit cycleComplete();
  emit treatmentEnded(baseline);
  isTreatmentOperating = false;
  offsetsApplied = 0;
  for (int i = 0; i < NUM_FEEDBACK_ROUNDS; i++)
  {
    for (int j = 0; j < NUM_OFFSETS; j++)
    {
      feedbackFreqs[i][j] = 0;
    }
  }
}

void EEGSensor::errorHandler()
{
  // error handler event loop
  int msElapsed = 0;

  while((isConnectionsBroken || isBatteryLow) && isSensorOperating)
  {
    msElapsed += 100;
    if (msElapsed >= FIVE_MINUTES_MS || !isSensorOperating)
    {
      emit fiveMinutesDisconnected();
    }
    QThread::msleep(100);
  }
}

void EEGSensor::pauseHandler()
{
  while (!(isConnectionsBroken || isBatteryLow) && isTreatmentOperating && isSensorOperating && isTreatmentPaused)
  {
    QThread::msleep(100);
  }
}

void EEGSensor::initializeValues()
{
  // Initializer for randomly generated freq, amplitude values for brainwave bands on ctor and treatment cycle
  // Amplitude "amp" values are generated off of a "normal" range of 20-200 microvolts (the internet told me so)
  // in theory, max amplitude for combined waveform 800 microvolts

  // generating frequencies as uniform distribution for efficiency - distribution was not specified
  alphaFreq = ALPHA_MIN + QRandomGenerator::global()->generateDouble() * (ALPHA_MAX - ALPHA_MIN);
  alphaAmp = 20 + QRandomGenerator::global()->generateDouble() * 180;

  betaFreq = BETA_MIN + QRandomGenerator::global()->generateDouble() * (BETA_MAX - BETA_MIN);
  betaAmp = 20 + QRandomGenerator::global()->generateDouble() * 180;

  thetaFreq = THETA_MIN + QRandomGenerator::global()->generateDouble() * (THETA_MAX - THETA_MIN);
  thetaAmp = 20 + QRandomGenerator::global()->generateDouble() * 180;

  deltaFreq = DELTA_MIN + QRandomGenerator::global()->generateDouble() * (DELTA_MAX - DELTA_MIN);
  deltaAmp = 20 + QRandomGenerator::global()->generateDouble() * 180;
}

void EEGSensor::resetSensorValues()
{
  alphaAmp = betaAmp = thetaAmp = deltaAmp = 0;

  for (int i = 0; i < NUM_FEEDBACK_ROUNDS; i++)
  {
    for (int j = 0; j < NUM_OFFSETS; j++)
    {
      feedbackFreqs[i][j] = 0;
    }
  }
}

double EEGSensor::getBaselineFreq() const
{
  float feedbackSum = 0;
  for (int i = 0; i < NUM_FEEDBACK_ROUNDS; i++)
  {
    for (int j = 0; j < NUM_OFFSETS; j++)
    {
      feedbackSum += feedbackFreqs[i][j] * OFFSET_FREQ_STRENGTH;
    }
  }

  return (alphaFreq * alphaAmp +
          betaFreq * betaAmp +
          thetaFreq * thetaAmp +
          deltaFreq * deltaAmp +
          feedbackSum)/
      (alphaAmp + betaAmp + thetaAmp + deltaAmp + offsetsApplied * OFFSET_FREQ_STRENGTH);
}
