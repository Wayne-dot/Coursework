
#include "City.h"
#include <cstring>
#include <iostream>
#include <string.h>

using namespace std;

City::City(): id(0){
    strncpy(name, "Unknown", sizeof(name) - 1);  // Safe copy of name
    name[sizeof(name) - 1] = '\0';  // Null-terminate the string
    for (int i = 0; i < 12; ++i) {
        rainfall[i] = 0.0;
    }
}

void City::setData(int new_id, string new_name, float new_data[20]){
    id = new_id;

    strncpy(name, new_name.c_str(), sizeof(name) - 1); // Copy up to the size of name - 1
    name[sizeof(name) - 1] = '\0';  // Ensure null-termination

    // Copy rainfall data array
    for (int i = 0; i < 12; i++) {  // Assuming there are 12 months of rainfall data
        rainfall[i] = new_data[i];
    }
}

float City::getAverageRainfall() const{
    float sum = 0;
    for(int i = 0 ; i < 12 ; i++){
        sum += rainfall[i];
    }
    return sum / 12;
}

float City::getMinRainfall() const{
    float min = rainfall[0];
    for(int i = 0 ; i < 12 ; i++){
        if (rainfall[i] < min){
            min = rainfall[i];
        }
    }
    return min;
}

float City::getMaxRainfall() const{
    float max = rainfall[0];
    for(int i = 0 ; i < 12 ; i++){
        if (rainfall[i] > max){
            max = rainfall[i];
        }
    }
    return max;
}


void City::displayCityStats() const{
    cout << "City: " << name << endl;
    cout << "Min Rainfall: " << getMinRainfall() << " mm" << endl;
    cout << "Max Rainfall: " << getMaxRainfall() << " mm" << endl;
    cout << "Average Rainfall: " << getAverageRainfall() << " mm" << endl;
    
}