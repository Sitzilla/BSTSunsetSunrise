#include <iostream>
#include <string>
#include "day.h"
using namespace std;

Day::Day() {};
Day::Day(int year, int month, int day, int pSunrise, int pSunset) {
    date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    sunrise = pSunrise;
    sunset = pSunset;
}

string Day::getDate() {
    return date;
}

void Day::print() {
    cout << "Day " << date << endl;
    cout << "Sunrise " << sunrise << endl;
    cout << "Sunset " << sunset << endl << endl;
}
