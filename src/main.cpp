#include <Arduino.h>
#include "GsmService.h"

GsmService gsmService;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Garage Control System...");

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
  // put your main code here, to run repeatedly:
}
