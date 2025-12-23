#include "GsmService.h"

GsmService::GsmService() {
    // Use Serial2 for GSM
    _serial = &Serial2;
    _modem = new TinyGsm(*_serial);
}

bool GsmService::init() {
    pinMode(SIM800_RST_PIN, OUTPUT);
    digitalWrite(SIM800_RST_PIN, HIGH); // Default state
    
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
    if (_serial->available()) {
        String line = _serial->readStringUntil('\n');
        if (line.indexOf("RING") != -1) {
            return _modem->getCallerID();
        }
    }
    return "";
}

bool GsmService::hangup() {
    return _modem->callHangup();
}

bool GsmService::getIncomingSMS(SMS &sms) {
    if (_serial->available()) {
        String line = _serial->readStringUntil('\n');
        if (line.indexOf("+CMTI:") != -1) {
            int index = line.substring(line.lastIndexOf(',') + 1).toInt();
            String sender = "";
            String message = _modem->readSMS(index, sender);
            if (message != "") {
                sms.sender = sender;
                sms.message = message;
                _modem->deleteSMS(index);
                return true;
            }
        }
    }
    return false;
}

bool GsmService::sendSMS(String number, String message) {
    return _modem->sendSMS(number, message);
}

void GsmService::reset() {
    Serial.println("Hardware resetting SIM800L...");
    digitalWrite(SIM800_RST_PIN, LOW);
    delay(100);
    digitalWrite(SIM800_RST_PIN, HIGH);
    delay(3000);
    init();
}