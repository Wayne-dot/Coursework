
#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car{
    private:
        string make;
        string model;
        int year;
        int speed;
    public:
        Car();
        Car(string mk, string mod, int yr, int sp);

        void accelerate(int amount);
        void breake(int amount);
        void displayInfo() const;
};


#endif