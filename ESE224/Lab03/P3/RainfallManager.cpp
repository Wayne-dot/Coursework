
#include "RainfallManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

RainfallManager::RainfallManager(){
    
}


void RainfallManager::loadDataFromFile(const char* filename){
    ifstream inputfile(filename);
    
    if(!inputfile){
        cerr << "File can not be found" << endl;
    }

    
    inputfile >> num_of_cities;
    inputfile.ignore();

    string citiname, line, string_rainfall_data;
    float rainfall;
    float rainfall_data[12];

    for(int i = 0 ; i < num_of_cities ; i++){

        getline(inputfile, line);

        citiname = line.substr(0, line.find(":"));
        string_rainfall_data = line.substr(line.find(":") + 1);

        stringstream ss(string_rainfall_data);
        int j = 0;
        while(ss >> rainfall){

            rainfall_data[j] = rainfall;
            j++;
            if(ss.peek() == ','){
                ss.ignore();
            }
        }
        cities[i].setData(i, citiname, rainfall_data);
    }
}


City RainfallManager::getCityWithMaxRainfall() const{
    City Max = cities[0];
    for(int i = 0 ; i < num_of_cities ; i++){
        if(cities[i].getMaxRainfall() > Max.getMaxRainfall() ){
            Max = cities[i];
        }
    }
    return Max;
}

City RainfallManager::getCityWithMinRainfall() const{
    City Min = cities[0];
    for(int i = 0 ; i < num_of_cities ; i++){
        if(cities[i].getMaxRainfall() < Min.getMaxRainfall() ){
            Min = cities[i];
        }
    }
    return Min;
}

void RainfallManager::displayAllStats() const{
    for(int i = 0 ; i < num_of_cities ; i++){
        cities[i].displayCityStats();
        cout << "--------------------" << endl;
    }
}