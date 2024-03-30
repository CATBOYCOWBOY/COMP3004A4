#ifndef SENSORPOOL_H
#define SENSORPOOL_H

class SensorPool {
    public:
        // constructor
        SensorPool();

        // destructor
        ~SensorPool();

        // getters | setters
        bool getAllConnected();
        void setAllConnected();
    private:
        bool allConnected = true;

};
#endif
