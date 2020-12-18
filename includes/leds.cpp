#include <Adafruit_NeoPixel.h>

#include "lightSensor.cpp"
#include "leds.h"

#define LED_PIN 2 //D4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void leds::setup() {
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void leds::loop(){
    for (int i = 0; i < 20; i++)
    {
        lightSensor::getLightLevel();
        strip.setPixelColor(i, strip.Color(100, 50, 200));
        strip.setBrightness(brightness);
        strip.show();
        delay(1000);
    }
    for (int i = 0; i < LED_COUNT; i++)
    {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
    strip.show();
}