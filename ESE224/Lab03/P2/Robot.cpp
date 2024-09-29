
#include "Robot.h"
#include <cstring>
#include <iostream>
#include <ostream>

using namespace std;

Robot::Robot() : energy(70), power(50), speed(30){

}

bool Robot::checkEvolution() const{
    if(energy > 90 && power > 60 && speed > 40){
        return true;
    }
    return false;
}

void Robot::applyEvent(const char*eventType, float effect){
    if(strcmp(eventType, "Energy") == 0){
        energy += effect;
    }
    else if(strcmp(eventType, "Power") == 0){
        power += effect;
    }
    else if(strcmp(eventType, "Speed") == 0){
        speed += effect;
    }
}

void Robot::displayStats() const{
    cout << "Energy: " << energy << endl;
    cout << "Power: " << power << endl;
    cout << "Speed: " << speed << endl;
    cout << "-------------------" << endl;
}