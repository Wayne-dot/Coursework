
#include <iostream>
#include "RainfallManager.h"
// #include "City.h"

using namespace std;

int main(){

    RainfallManager manager;
    manager.loadDataFromFile("rainfall_data.txt");
    manager.displayAllStats();

    City maxCity = manager.getCityWithMaxRainfall();
    City minCity = manager.getCityWithMinRainfall();

    cout << "City with Maximum Average Rainfall: " << endl;
    maxCity.displayCityStats();

    cout << "City with Minimum Average Rainfall: " << endl;
    minCity.displayCityStats();

    return 0;
}