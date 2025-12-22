#include "GsmService.h"

GsmService::GsmService() {
    // Use Serial2 for GSM
    _serial = &Serial2;
    _modem = new TinyGsm(*_serial);
}

bool GsmService::init() {
    // Begin serial communication
    _serial->begin(9600, SERIAL_8N1, SIM800_RX_PIN, SIM800_TX_PIN);
    delay(3000); // Wait for module to stabilize

    // Restart takes quite some time
    // To skip it, call init() instead of restart()
    // _modem->restart(); 
    return _modem->init();
}

bool GsmService::testAT() {
    return _modem->testAT();
}

bool GsmService::waitForNetwork() {
    return _modem->waitForNetwork();
}

int GsmService::getSignalQuality() {
    return _modem->getSignalQuality();
}