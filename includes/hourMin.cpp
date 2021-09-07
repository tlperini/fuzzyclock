#include <Adafruit_NeoPixel.h>
#include "hourMin.h"

#define LED_PIN 2 //D4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void hourMin::setup() {
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            // Turn OFF all pixels ASAP
    strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
    previousMinute = -1;
    previousHour = -1;
}

void hourMin::loop(){
    // if ((previousMinute != currentMinute) || (tempStatus == 1))
    if (previousMinute != currentMinute)
    {
        // tempStatus = 0;
        lightSensor::getLightLevel();
        printItIs();
        printMinutes();
        printMinOclock();
        printToPast();
        printHours();
    }
}

void hourMin::printItIs()
{
    for (int i = 0; i < sizeof(itisLEDS) / sizeof(itisLEDS[0]); i++)
    {
        strip.setPixelColor(itisLEDS[i], strip.Color(colorR, colorG, colorB));
    }
    strip.setBrightness(brightness);
    strip.show();
}

void hourMin::printMinOclock()
{
    if (currentMinute == 1)
    {
        clearLEDS(time_minutes[0]);
        printMinLEDS(minuteLEDS); // print "minute" when first minute of the hour
    }
    else if (currentMinute % 15 != 0 && currentMinute > 0) // do not print "minutes" when quarter, half or o'clock
    {
        clearLEDS(minuteLEDS);
        printMinLEDS(minutesLEDS);
    }
    else
    {
        clearLEDS(minutesLEDS);
    }
}

void hourMin::printToPast()
{
    if (currentMinute == 0)
    {
        stateTo = 0;
        statePast = 0;
    }
    if (stateTo == 0)
    {
        clearLEDS(toLEDS);
    }
    else
    {
        printMinLEDS(toLEDS);
    }
    if (statePast == 0)
    {
        clearLEDS(pastLEDS);
    }
    else
    {
        printMinLEDS(pastLEDS);
    }
}

void hourMin::printMinutes()
{
    clearLEDS(time_minutes[min10]);
    clearLEDS(time_minutes[min1]);

    if (currentMinute <= 20)
    {
        min10 = currentMinute;
        min1 = 25;
        stateTo = 0;
        statePast = 1;
    }
    else
    {
        if (currentMinute >= 40 && currentMinute % 5 == 0) // if current minute is greater than forty and multiple of five
        {
            min10 = 60 - currentMinute; // ex: if 45, min10 receives 15
            min1 = 25;
            stateTo = 1;
            statePast = 0;
        }
        else if (currentMinute == 30)
        {
            min10 = 24;
            min1 = 25;
            stateTo = 0;
            statePast = 1;
        }
        else if (currentMinute == 35)
        {
            min10 = 20;
            min1 = 5;
            stateTo = 1;
            statePast = 0;
        }
        else
        {
            min10 = floor(currentMinute / 10) * 10; // ex: if 43, min10 receives 40; floor(43/10) = 4
            min1 = currentMinute - min10;
            stateTo = 0;
            statePast = 1;
        }

        switch (min10)
        {
        case 30:
            min10 = 21;
            break;
        case 40:
            min10 = 22;
            break;
        case 50:
            min10 = 23;
            break;
        }
    }
    printMinLEDS(time_minutes[min10]);
    printMinLEDS(time_minutes[min1]);
    previousMinute = currentMinute;
}

void hourMin::printHours()
{
    if (currentHour != previousHour)
    {
        clearLEDS(time_hours[timeHour]);
    }

    if (currentHour > 12)
    {
        timeHour = currentHour - 12;
    }
    else
    {
        timeHour = currentHour;
    }

    if (timeHour == 0 || timeHour == 12)
    {
        timeHour = 0;
    }
    if (stateTo == 1 && timeHour != 11)
    {
        clearLEDS(time_hours[timeHour]);
        timeHour++;
        currentHour++;
    }
    else if (stateTo == 1 && timeHour == 11)
    {
        clearLEDS(time_hours[timeHour]);
        timeHour = 0;
        currentHour++;
    }
    printHrLEDS(time_hours[timeHour]);
    previousHour = currentHour;
}

void hourMin::printMinLEDS(int minLEDS[9])
{
    for (int i = 0; i < 9; i++)
    {
        strip.setPixelColor(minLEDS[i], strip.Color(colorR, colorG, colorB));
    }
    strip.setBrightness(brightness);
    strip.show();
}

void hourMin::printHrLEDS(int hrLEDS[6])
{
    for (int i = 0; i < 6; i++)
    {
        strip.setPixelColor(hrLEDS[i], strip.Color(colorR, colorG, colorB));
    }
    strip.setBrightness(brightness);
    strip.show();
}

void hourMin::clearLEDS(int minLEDS[9])
{
    for (int i = 0; i < 9; i++)
    {
        strip.setPixelColor(minLEDS[i], strip.Color(0, 0, 0));
    }
    strip.show();
}