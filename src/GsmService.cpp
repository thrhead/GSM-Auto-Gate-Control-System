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

String GsmService::getIncomingCallNumber() {
    // Check if there is data from the modem
    if (_serial->available()) {
        String line = _serial->readStringUntil('\n');
        if (line.indexOf("RING") != -1) {
            // After RING, we wait for CLIP (Caller ID)
            // TinyGsm can help get the caller ID
            return _modem->getCallerID();
        }
    }
    return "";
}

