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

void setup() {
    delay(2000);
    UNITY_BEGIN();
    RUN_TEST(test_gsm_init);
    RUN_TEST(test_gsm_network);
    UNITY_END();
}

void loop() {
}
