#include <Arduino.h>
#include "GsmService.h"
#include "RelayService.h"
#include "StorageService.h"

GsmService gsmService;
RelayService relayService;
StorageService storageService;

unsigned long lastNetworkCheck = 0;
const unsigned long networkCheckInterval = 60000; // 1 minute

void handleSMS(GsmService::SMS sms) {
    if (!storageService.isAdmin(sms.sender)) {
        Serial.print("Unauthorized SMS command from: ");
        Serial.println(sms.sender);
        return;
    }

    String msg = sms.message;
    msg.toUpperCase();
    msg.trim();

    if (msg.startsWith("EKLE:")) {
        String number = sms.message.substring(5);
        number.trim();
        if (storageService.addUser(number)) {
            gsmService.sendSMS(sms.sender, "NUMARA EKLENDI: " + number);
            Serial.println("User added via SMS: " + number);
        }
    } 
    else if (msg.startsWith("SIL:")) {
        String number = sms.message.substring(4);
        number.trim();
        if (storageService.removeUser(number)) {
            gsmService.sendSMS(sms.sender, "NUMARA SILINDI: " + number);
            Serial.println("User removed via SMS: " + number);
        }
    } 
    else if (msg == "DURUM") {
        std::vector<String> users = storageService.getUsers();
        int signal = gsmService.getSignalQuality();
        String response = "SISTEM AKTIF.\nSINYAL: " + String(signal) + "/31\nKULLANICI: " + String(users.size());
        gsmService.sendSMS(sms.sender, response);
    }
}

void notifyAdmins() {
    std::vector<String> admins = storageService.getAdmins();
    for (String admin : admins) {
        gsmService.sendSMS(admin, "GARAJ SISTEMI AKTIF EDILDI.");
    }
}

void setup() {
  Serial.begin(115200);
  Serial.println("--- Garage Control System v1.0 ---");

  relayService.init();
  storageService.init();

  if (gsmService.init()) {
    Serial.println("GSM Module Initialized.");
    if (gsmService.waitForNetwork()) {
        Serial.println("Network Connected.");
        notifyAdmins();
    } else {
        Serial.println("Network Connection Timed Out!");
    }
  } else {
    Serial.println("CRITICAL: GSM Module Initialization Failed!");
  }
}

void loop() {
  // Arama kontrolü
  String callerId = gsmService.getIncomingCallNumber();
  if (callerId != "") {
    Serial.println("Incoming Call Detected: " + callerId);
    gsmService.hangup();
    
    if (storageService.isUserAuthorized(callerId) || storageService.isAdmin(callerId)) {
        Serial.println("Access GRANTED for " + callerId);
        relayService.trigger();
    } else {
        Serial.println("Access DENIED for " + callerId);
    }
  }

  // SMS kontrolü
  GsmService::SMS incomingSms;
  if (gsmService.getIncomingSMS(incomingSms)) {
    Serial.println("SMS Received from " + incomingSms.sender);
    handleSMS(incomingSms);
  }

  // Periyodik ağ kontrolü
  if (millis() - lastNetworkCheck > networkCheckInterval) {
    lastNetworkCheck = millis();
    if (gsmService.testAT()) {
        // Modem responds
    } else {
        Serial.println("Modem not responding, re-initializing...");
        gsmService.init();
    }
  }

  delay(100);
}