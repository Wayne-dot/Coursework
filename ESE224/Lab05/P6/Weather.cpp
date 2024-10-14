
#include "Weather.h"
#include <iostream>

using namespace std;

Weather::Weather(){
}

void Weather::inputRainFall(){
    cout << "Enter rainfall data for the week (7 days): " << endl;
    for(int i = 0 ; i < 7 ; i++){
        cin >> rainfall[i];
    }
}

void Weather::calculateDaysToHigherRain(){
    for(int i = 0 ; i < 7 ; i++){
        daysToHigherRain[i] = 0;
    }

    bool exist = true;


    for(int i = 0 ; i < 7 ; i ++){
        // last element is always -1
        if(i == 6){
            daysToHigherRain[i] = -1;
        }
        for(int j = i + 1 ; j < 7 ; j++){
            daysToHigherRain[i] += 1;
            if(rainfall[j] < rainfall[i]){
                exist = false;
            }
            else if(rainfall[j] > rainfall[i]){
                break;
            }

            if(!exist && rainfall[j] < rainfall[i] && j == 6){
                daysToHigherRain[i] = -1;
            }
        }
    }
}

void Weather::displayRainfall(){
    cout << "Rainfall: [";
    for(int i = 0 ; i < 6 ; i++){
        cout << rainfall[i] << ", ";
    }
    cout << rainfall[6] << "]" << endl;
}

void Weather::displayDaysToHigherRain(){
    cout << "Days to next higher rainfall: [";
    for(int i = 0 ; i < 6 ; i++){
        cout << daysToHigherRain[i] << ", ";
    }
    cout << daysToHigherRain[6] << "]" << endl;
}