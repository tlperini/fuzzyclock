#include "includes/globals.cpp"
#include "includes/wifi.cpp"
#include "includes/lightSensor.cpp"
#include "includes/hourMin.cpp"
#include "includes/tempHum.cpp"
#include "includes/timeDate.cpp"

void setup() {
    // ESP.reset();
    Serial.begin(76800);
    wifi::setup();
    hourMin::setup();
    tempHum::setup();
    lightSensor::setup();
    timeDate::setup();
}

void loop() {
    timeDate::loop();
    tempHum::loop();
    hourMin::loop();
}