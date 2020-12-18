#include <NTPClient.h>
#include <WiFiUdp.h>

#include "timeDate.h"

void timeDate::setup()
{
    timeDate::timeClient.begin();
}

void timeDate::loop()
{
    timeDate::timeClient.update();
    currentHour = timeDate::timeClient.getHours();
    currentMinute = timeDate::timeClient.getMinutes();
}

// Define NTP Client to get time
WiFiUDP timeDate::ntpUDP;
NTPClient timeDate::timeClient = NTPClient(timeDate::ntpUDP, "pool.ntp.org", utcOffsetInSeconds);