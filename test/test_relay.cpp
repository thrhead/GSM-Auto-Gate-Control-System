#include <unity.h>
#include <Arduino.h>
#include "RelayService.h"

void setUp(void) {}
void tearDown(void) {}

void test_relay_init(void) {
    RelayService relay;
    relay.init();
    // Pin modunun OUTPUT ve LOW olduğunu fiziksel donanım olmadan 
    // ancak mock ile test edebiliriz, burada arayüz kontrolü yapıyoruz.
    TEST_ASSERT_EQUAL(LOW, digitalRead(RELAY_PIN));
}

void setup() {
    delay(2000);
    UNITY_BEGIN();
    RUN_TEST(test_relay_init);
    UNITY_END();
}

void loop() {}
