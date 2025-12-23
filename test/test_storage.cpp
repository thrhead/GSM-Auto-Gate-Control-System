#include <unity.h>
#include <Arduino.h>
#include "StorageService.h"

void setUp(void) {}
void tearDown(void) {}

void test_storage_add_user(void) {
    StorageService storage;
    storage.init();
    String testNum = "+905001112233";
    storage.addUser(testNum);
    TEST_ASSERT_TRUE(storage.isUserAuthorized(testNum));
}

void test_storage_remove_user(void) {
    StorageService storage;
    storage.init();
    String testNum = "+905001112233";
    storage.addUser(testNum);
    storage.removeUser(testNum);
    TEST_ASSERT_FALSE(storage.isUserAuthorized(testNum));
}

void setup() {
    delay(2000);
    UNITY_BEGIN();
    RUN_TEST(test_storage_add_user);
    RUN_TEST(test_storage_remove_user);
    UNITY_END();
}

void loop() {}
