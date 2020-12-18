#include <DHT.h>
#include "tempHum.h"
#define DHTPIN 0 //D3
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void tempHum::setup()
{
    dht.begin();
}

void tempHum::loop()
{
    getHumTemp();
}

void tempHum::getHumTemp()
{
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);
}