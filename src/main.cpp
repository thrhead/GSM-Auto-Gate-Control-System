#include <Arduino.h>
#include "GsmService.h"

GsmService gsmService;

void setup() {
  Serial.begin(115200);
  Serial.println("Garage Control System Initializing...");

  if (gsmService.init()) {
    Serial.println("GSM Module Initialized.");
    
    Serial.print("Waiting for network...");
    if (gsmService.waitForNetwork()) {
        Serial.println(" Connected.");
        Serial.print("Signal Quality: ");
        Serial.println(gsmService.getSignalQuality());
    } else {
        Serial.println(" Failed to connect to network.");
    }
  } else {
    Serial.println("GSM Module Initialization Failed!");
  }
}

void loop() {
  String callerId = gsmService.getIncomingCallNumber();
  if (callerId != "") {
    Serial.print("Incoming call from: ");
    Serial.println(callerId);
    // Future task: Handle authorization and relay
  }
  delay(100);
}