#include "RelayService.h"

RelayService::RelayService() : _pin(RELAY_PIN) {}

void RelayService::init() {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW); // Ensure relay is off initially
}

void RelayService::trigger(int durationMs) {
    digitalWrite(_pin, HIGH);
    delay(durationMs);
    digitalWrite(_pin, LOW);
}
