
#include "Car.h"

using namespace std;

int main(){

    Car car1;
    Car car2("Toyota", "Corolla", 2022, 60);

    car1.accelerate(50);
    car1.breake(10);
    car1.displayInfo();

    car2.accelerate(150);
    car2.displayInfo();
    return 0;
}