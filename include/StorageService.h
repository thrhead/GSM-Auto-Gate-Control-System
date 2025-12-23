#ifndef STORAGE_SERVICE_H
#define STORAGE_SERVICE_H

#include <Arduino.h>
#include <Preferences.h>
#include <vector>

class StorageService {
public:
    StorageService();
    void init();
    
    // Beyaz liste işlemleri
    bool addUser(String number);
    bool removeUser(String number);
    bool isUserAuthorized(String number);
    std::vector<String> getUsers();

    // Yönetici işlemleri
    bool addAdmin(String number);
    bool isAdmin(String number);
    std::vector<String> getAdmins();

private:
    Preferences _prefs;
    const char* _namespace = "garage_system";
};

#endif
