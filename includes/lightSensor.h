#ifndef lightSensor_H
#define lightSensor_H

class lightSensor
{
public:
    static void setup();
    static void getLightLevel();
    static unsigned int BH1750_Read();
    static void setBrightness();
};
#endif