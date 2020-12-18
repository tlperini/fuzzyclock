#include <Wire.h>
#include "lightSensor.h"

// SCL - D1
// SDA - D2

unsigned int lux;
int BH1750_Device = 0x23;

void lightSensor::setup()
{
    Wire.begin();
    Wire.beginTransmission(BH1750_Device);
    Wire.write(0x10); // sets resolution to 1 Lux
    Wire.endTransmission();
    delay(200);
}

void lightSensor::getLightLevel()
{
    colorR = 255;
    colorG = 255;
    colorB = 255;
    lux = BH1750_Read();
    setBrightness();
}

unsigned int lightSensor::BH1750_Read()
{

    unsigned int i = 0;
    Wire.beginTransmission(BH1750_Device);
    Wire.requestFrom(BH1750_Device, 2);
    while (Wire.available())
    {
        i <<= 8;
        i |= Wire.read();
    }
    Wire.endTransmission();
    return i / 1.2; // Convert to Lux
}

void lightSensor::setBrightness()
{
    if (lux > 100)
    {
        lux = 100;
    }
    else if (lux < 10)
    {
        lux = 10;
    }
    brightness = floor(lux / 10) * 10;
}