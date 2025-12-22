#include <unity.h>
#include <Arduino.h>
#include "GsmService.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_gsm_init(void) {
    GsmService gsm;
    TEST_ASSERT_FALSE(gsm.init()); 
}

void test_gsm_network(void) {
    GsmService gsm;
    // Without hardware, these are expected to fail or return 0
    TEST_ASSERT_FALSE(gsm.waitForNetwork());
    TEST_ASSERT_EQUAL(0, gsm.getSignalQuality());
}

void test_gsm_incoming_call(void) {
    GsmService gsm;
    // Interface check: should return empty string if no call
    TEST_ASSERT_EQUAL_STRING("", gsm.getIncomingCallNumber().c_str());
}

void test_gsm_hangup(void) {
    GsmService gsm;
    // Interface check: should return false if no call to hangup
    TEST_ASSERT_FALSE(gsm.hangup());
}

void setup() {
    delay(2000);
    UNITY_BEGIN();
    RUN_TEST(test_gsm_init);
    RUN_TEST(test_gsm_network);
    RUN_TEST(test_gsm_incoming_call);
    RUN_TEST(test_gsm_hangup);
    UNITY_END();
}

void loop() {
}
