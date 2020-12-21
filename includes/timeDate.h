#ifndef timeDate_H
#define timeDate_H
long NTPUPDATE;

// Set timezone (seconds)
const long utcOffsetInSeconds = -10800;

class timeDate
{
public:
    static void setup();
    static void loop();
    static WiFiUDP ntpUDP;
    static NTPClient timeClient;
};
#endif