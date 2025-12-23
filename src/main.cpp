#include <Arduino.h>
#include "GsmService.h"
#include "RelayService.h"
#include "StorageService.h"

GsmService gsmService;
RelayService relayService;
StorageService storageService;

void setup() {
  Serial.begin(115200);
  Serial.println("Garage Control System Initializing...");

  relayService.init();
  storageService.init();

  // Test için ilk yöneticiyi ekleyelim (Eğer listede yoksa)
  // NOT: Gerçek uygulamada bu numarayı buraya bir kez yazıp sonra silebilirsiniz.
  // storageService.addAdmin("+905XXXXXXXXX"); 

  if (gsmService.init()) {
    Serial.println("GSM Module Initialized.");
    
    if (gsmService.waitForNetwork()) {
        Serial.println("Connected to Network.");
    } else {
        Serial.println("Network Connection Failed.");
    }
  } else {
    Serial.println("GSM Module Failed!");
  }
}

void loop() {
  String callerId = gsmService.getIncomingCallNumber();
  if (callerId != "") {
    Serial.print("Incoming call from: ");
    Serial.println(callerId);
    
    // Auto-reject
    gsmService.hangup();
    Serial.println("Call rejected.");
    
    // Authorization Check
    if (storageService.isUserAuthorized(callerId) || storageService.isAdmin(callerId)) {
        Serial.println("Authorized! Opening garage door...");
        relayService.trigger();
    } else {
        Serial.println("Unauthorized access attempt denied.");
    }
  }
  delay(100);
}
