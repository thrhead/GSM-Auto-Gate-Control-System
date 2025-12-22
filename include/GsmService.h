#ifndef GSM_SERVICE_H
#define GSM_SERVICE_H

#include <Arduino.h>

// Define GSM modem model for TinyGSM
#define TINY_GSM_MODEM_SIM800
#include <TinyGsmClient.h>

// Pin Definitions (Adjust as needed for specific board)
#define SIM800_RX_PIN 16
#define SIM800_TX_PIN 17
#define SIM800_RST_PIN 5 

class GsmService {
public:
    GsmService();
    bool init();
    bool testAT();
    bool waitForNetwork();
    int getSignalQuality();

private:
    HardwareSerial* _serial;
    TinyGsm* _modem;
};

#endif
