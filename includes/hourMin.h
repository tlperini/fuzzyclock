#ifndef hourMin_H
#define hourMin_H
int itisLEDS[] = {0, 1, 3, 4};
int minuteLEDS[9] = {119, 120, 121, 122, 123, 124, -1, -1, -1};
int minutesLEDS[9] = {119, 120, 121, 122, 123, 124, 125, -1, -1};
int pastLEDS[9] = {139, 138, 137, 136, -1, -1, -1, -1, -1};
int toLEDS[9] = {134, 133, -1, -1, -1, -1, -1, -1, -1};
int previousMinute;
int previousHour;
int timeHour = -1;
int timeMinute = -1;
int min10 = -1;
int min1 = -1;
int stateTo = 1;
int statePast = 0;

int time_minutes[26][9] = {
    {187, 186, 185, 184, 183, 182, -1, -1, -1},  // o'clock
    {81, 80, 79, -1, -1, -1, -1, -1, -1},        // one
    {83, 82, 81, -1, -1, -1, -1, -1, -1},        // two
    {84, 85, 86, 87, 88, -1, -1, -1, -1},        // three
    {90, 91, 92, 93, -1, -1, -1, -1, -1},        // four
    {66, 67, 68, 69, -1, -1, -1, -1, -1},        // five
    {111, 110, 109, -1, -1, -1, -1, -1, -1},     // six
    {56, 57, 58, 59, 60, -1, -1, -1, -1},        // seven
    {49, 48, 47, 46, 45, -1, -1, -1, -1},        // eight
    {105, 104, 103, 102, -1, -1, -1, -1, -1},    // nine
    {78, 77, 76, -1, -1, -1, -1, -1, -1},        // ten
    {112, 113, 114, 115, 116, 117, -1, -1, -1},  // eleven
    {75, 74, 73, 72, 71, 70, -1, -1, -1},        // twelve
    {21, 20, 19, 18, 17, 16, 15, 14, -1},        // thirteen
    {90, 91, 92, 93, 94, 95, 96, 97, -1},        // fourteen
    {7, 28, 29, 30, 31, 32, 33, 34, -1},         // a quarter (fifteen)
    {111, 110, 109, 108, 107, 106, 105, -1, -1}, // sixteen
    {56, 57, 58, 59, 60, 61, 62, 63, 64},        // seventeen
    {49, 48, 47, 46, 45, 44, 43, 42, -1},        // eighteen
    {105, 104, 103, 102, 101, 100, 99, 98, -1},  // nineteen
    {27, 26, 25, 24, 23, 22, -1, -1, -1},        // twenty
    {36, 37, 38, 39, 40, 41, -1, -1, -1},        // thirty
    {55, 54, 53, 52, 51, -1, -1, -1, -1},        // forty
    {9, 10, 11, 12, 13, -1, -1, -1, -1},         // fifty
    {6, 7, 8, 9, -1, -1, -1, -1, -1},            // half
    {-1, -1, -1, -1, -1, -1, -1, -1, -1}         // empty
};

int time_hours[12][6] = {
    {195, 194, 193, 192, 191, 190}, // twelve
    {168, 169, 170, -1, -1, -1},    // one
    {179, 180, 181, -1, -1, -1},    // two
    {131, 130, 129, 128, 127, -1},  // three
    {145, 146, 147, 148, -1, -1},   // four
    {167, 166, 165, 164, -1, -1},   // five
    {176, 177, 178, -1, -1, -1},    // six
    {140, 141, 142, 143, 144, -1},  // seven
    {149, 150, 151, 152, 153, -1},  // eight
    {171, 172, 173, 174, -1, -1},   // nine
    {163, 162, 161, -1, -1, -1},    // ten
    {160, 159, 158, 157, 156, 155}  // eleven
};

class hourMin
{
public:
    static void setup();
    static void loop();
    static void printItIs();
    static void printToPast();
    static void printMinutes();
    static void printHours();
    static void printMinOclock();
    static void printMinLEDS(int minLEDS[9]);
    static void printHrLEDS(int hrLEDS[6]);
    static void clearLEDS(int minLEDS[9]);
};
#endif