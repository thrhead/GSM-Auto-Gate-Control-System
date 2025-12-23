#include "StorageService.h"

StorageService::StorageService() {}

void StorageService::init() {
    _prefs.begin(_namespace, false);
}

bool StorageService::addUser(String number) {
    if (isUserAuthorized(number)) return true;
    
    String users = _prefs.getString("users", "");
    if (users != "") users += ",";
    users += number;
    
    return _prefs.putString("users", users) > 0;
}

bool StorageService::removeUser(String number) {
    String users = _prefs.getString("users", "");
    if (users == "") return false;

    String newUsers = "";
    bool found = false;
    
    // Basit bir parçalama mantığı
    int start = 0;
    int end = users.indexOf(',');
    while (true) {
        String current = (end == -1) ? users.substring(start) : users.substring(start, end);
        if (current != number) {
            if (newUsers != "") newUsers += ",";
            newUsers += current;
        } else {
            found = true;
        }
        
        if (end == -1) break;
        start = end + 1;
        end = users.indexOf(',', start);
    }
    
    if (found) {
        _prefs.putString("users", newUsers);
    }
    return found;
}

bool StorageService::isUserAuthorized(String number) {
    String users = _prefs.getString("users", "");
    if (users == "") return false;
    
    return users.indexOf(number) != -1;
}

std::vector<String> StorageService::getUsers() {
    std::vector<String> list;
    String users = _prefs.getString("users", "");
    if (users == "") return list;

    int start = 0;
    int end = users.indexOf(',');
    while (true) {
        String current = (end == -1) ? users.substring(start) : users.substring(start, end);
        list.push_back(current);
        if (end == -1) break;
        start = end + 1;
        end = users.indexOf(',', start);
    }
    return list;
}

bool StorageService::addAdmin(String number) {
    String admins = _prefs.getString("admins", "");
    if (admins.indexOf(number) != -1) return true;
    
    if (admins != "") admins += ",";
    admins += number;
    return _prefs.putString("admins", admins) > 0;
}

bool StorageService::isAdmin(String number) {
    String admins = _prefs.getString("admins", "");
    return admins.indexOf(number) != -1;
}
