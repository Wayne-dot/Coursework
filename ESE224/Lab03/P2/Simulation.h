#ifndef Simulation_H
#define Simulation_H

#include "Robot.h"
#include <iostream>

using namespace std;

class Simulation{
    private:
        Robot robot;
        string fname;
    public:
        Simulation(const Robot& rob);
        void loadDataFromFile(const char*filename);
        void run();
};

#endif