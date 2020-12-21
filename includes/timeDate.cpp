#include <NTPClient.h>
#include <WiFiUdp.h>
#include <TimeLib.h>

#include "timeDate.h"

void timeDate::setup()
{
    timeDate::timeClient.begin();
    timeDate::timeClient.update();
    currentTime = timeDate::timeClient.getEpochTime();
    setTime(currentTime);
    NTPUPDATE = currentTime + NTP_UPDATE;
}

void timeDate::loop()
{
    if (currentTime >= NTPUPDATE)
    {
        Serial.println("Updating NTP Client...");
        timeDate::timeClient.update();
        currentTime = timeDate::timeClient.getEpochTime();
        setTime(currentTime);
        Serial.print("Current Time: ");
        Serial.println(currentTime);
    }
    currentTime = now();
    currentHour = (currentTime % 86400L) / 3600;
    currentMinute = (currentTime % 3600) / 60;
    // Serial.println(currentTime);
    // Serial.println(currentHour);
    // Serial.println(currentMinute);
}

// Define NTP Client to get time
WiFiUDP timeDate::ntpUDP;
NTPClient timeDate::timeClient = NTPClient(timeDate::ntpUDP, "pool.ntp.org", utcOffsetInSeconds);