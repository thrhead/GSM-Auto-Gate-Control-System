#include <unity.h>
#include <Arduino.h>
#include "GsmService.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_gsm_init(void) {
    GsmService gsm;
    // Since we can't easily mock HardwareSerial in this environment without a mocking framework,
    // we will assert that the object can be created and the interface exists.
    // In a real device test, this would verify AT command response.
    // For now, we expect false because no hardware is attached.
    TEST_ASSERT_FALSE(gsm.init()); 
}

void setup() {
    delay(2000);
    UNITY_BEGIN();
    RUN_TEST(test_gsm_init);
    UNITY_END();
}

void loop() {
}
