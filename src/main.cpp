#include <Arduino.h>
#include "GsmService.h"

GsmService gsmService;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Garage Control System...");

  if (gsmService.init()) {
    Serial.println("GSM Module Initialized.");
  } else {
    Serial.println("GSM Module Initialization Failed!");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}