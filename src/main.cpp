#include <Arduino.h>
#include "GsmService.h"
#include "RelayService.h"
#include "StorageService.h"

GsmService gsmService;
RelayService relayService;
StorageService storageService;

void handleSMS(GsmService::SMS sms) {
    if (!storageService.isAdmin(sms.sender)) {
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
        }
    } 
    else if (msg.startsWith("SIL:")) {
        String number = sms.message.substring(4);
        number.trim();
        if (storageService.removeUser(number)) {
            gsmService.sendSMS(sms.sender, "NUMARA SILINDI: " + number);
        }
    } 
    else if (msg == "DURUM") {
        std::vector<String> users = storageService.getUsers();
        String response = "SISTEM AKTIF. KAYITLI KULLANICI SAYISI: " + String(users.size());
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
  Serial.println("Garage Control System Initializing...");

  relayService.init();
  storageService.init();

  if (gsmService.init()) {
    Serial.println("GSM Module Initialized.");
    if (gsmService.waitForNetwork()) {
        Serial.println("Connected to Network.");
        notifyAdmins();
    }
  } else {
    Serial.println("GSM Module Failed!");
  }
}

void loop() {
  String callerId = gsmService.getIncomingCallNumber();
  if (callerId != "") {
    gsmService.hangup();
    if (storageService.isUserAuthorized(callerId) || storageService.isAdmin(callerId)) {
        relayService.trigger();
    }
  }

  GsmService::SMS incomingSms;
  if (gsmService.getIncomingSMS(incomingSms)) {
    handleSMS(incomingSms);
  }

  delay(100);
}
