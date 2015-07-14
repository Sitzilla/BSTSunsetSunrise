#ifndef DAY_H
#define DAY_H

#include <string>
using namespace std;

class Day {
    public:
        Day(int year, int month, int day, int pSunrise, int pSunset);
        string getDate();
        void print();
    private:
        string date;
        int sunrise;
        int sunset;
};

#endif
