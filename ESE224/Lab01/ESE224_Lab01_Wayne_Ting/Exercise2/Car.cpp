

#include "Car.h"

#include <iostream>
#include <ostream>

using namespace std;

Car::Car() : make(""), model(""), year(0), speed(0){

}

Car::Car(string mk, string mod, int yr, int sp): make(mk), model(mod), year(yr), speed(sp){

}

void Car::accelerate(int amount){
    speed = speed + amount;
    if(speed > 200){
        speed = 200;
    }
}

void Car::breake(int amount){
    speed = speed - amount;
    if(speed < 0){
        speed = 0;
    }
}

void Car::displayInfo() const{
    cout << "Car Maker: " << make << ", Car model: " << model << ", year: " << year << " with speed of " << speed << endl;
}