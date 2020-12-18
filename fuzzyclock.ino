#include "includes/globals.cpp"
#include "includes/wifi.cpp"
#include "includes/leds.cpp"
#include "includes/tempHum.cpp"

void setup() {
    // ESP.reset();
    Serial.begin(9600);
    wifi::setup();
    leds::setup();
    tempHum::setup();
    lightSensor::setup();
}

void loop() {
    // put your main code here, to run repeatedly:
    tempHum::loop();
    leds::loop();
}