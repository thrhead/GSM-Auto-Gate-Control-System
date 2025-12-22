#include <Arduino.h>
#include "GsmService.h"
#include "RelayService.h"

GsmService gsmService;
RelayService relayService;

void setup() {
  Serial.begin(115200);
  Serial.println("Garage Control System Initializing...");

  relayService.init();

  if (gsmService.init()) {
    Serial.println("GSM Module Initialized.");
    
    Serial.print("Waiting for network...");
    if (gsmService.waitForNetwork()) {
        Serial.println(" Connected.");
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
    
    // Auto-reject call
    gsmService.hangup();
    Serial.println("Call rejected.");
    
    // Trigger relay (1 second pulse)
    Serial.println("Triggering relay...");
    relayService.trigger();
    Serial.println("Relay triggered.");
  }
  delay(100);
}