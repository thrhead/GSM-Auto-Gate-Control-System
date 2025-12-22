#ifndef RELAY_SERVICE_H
#define RELAY_SERVICE_H

#include <Arduino.h>

#define RELAY_PIN 23 // Standard GPIO for relay

class RelayService {
public:
    RelayService();
    void init();
    void trigger(int durationMs = 1000);

private:
    int _pin;
};

#endif
