
#include "Weather.h"

using namespace std;

int main(){

    Weather weather;
    weather.inputRainFall();
    weather.displayRainfall();
    weather.calculateDaysToHigherRain();
    weather.displayDaysToHigherRain();

    return 0;
}