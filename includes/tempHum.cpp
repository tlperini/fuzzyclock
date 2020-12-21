#include <DHT.h>
#include "tempHum.h"
#define DHTPIN 0 //D3
#define BUTPIN 15 //D8
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void tempHum::setup()
{
    dht.begin();
    tempStatus = 0;
}

void tempHum::loop()
{
    while(digitalRead(BUTPIN) == HIGH)
    {
        tempStatus = 1;
        lightSensor::getLightLevel();
        getHumTemp();
        showTempHum();
        delay(2000);
    }
}

void tempHum::getHumTemp()
{
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
}

void tempHum::showTempHum()
{
    clearTempLEDS();
    decTemp = floor(temperature / 10) * 10;
    unitTemp = temperature - decTemp;
    decTemp = decTemp / 10;
    printTempLEDS(decLEDS[decTemp]);
    printTempLEDS(unitLEDS[unitTemp]);
    printTempLEDS(degreeLEDS);
    delay(5000);
    clearTempLEDS();
    decHum = floor(humidity / 10) * 10;
    unitHum = humidity - decHum;
    decHum = decHum / 10;
    printTempLEDS(decLEDS[decHum]);
    printTempLEDS(unitLEDS[unitHum]);
    printTempLEDS(percentLEDS);
    delay(5000);
    clearTempLEDS();
}

void tempHum::clearTempLEDS()
{
    for (int i = 0; i < LED_COUNT; i++)
    {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
    strip.show();
}

void tempHum::printTempLEDS(int tempLEDS[19])
{
    for (int i = 0; i < 19; i++)
    {
        strip.setPixelColor(tempLEDS[i], strip.Color(colorR, colorG, colorB));
    }
    strip.setBrightness(brightness);
    strip.show();
}