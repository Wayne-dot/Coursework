
#include <fstream>
#include <iostream>

#include "Simulation.h"
#include "Robot.h"

using namespace std;

int main(){
    Robot robot;
    Simulation simulate(robot);

    ifstream inputFile("robot_events.txt");

    if(!inputFile){
        cerr << "Error opening file!" << endl;
        return 1;
    }
    
    // load input file
    simulate.loadDataFromFile("robot_events.txt");

    // run simulation
    simulate.run();

    // display result, whether or not the robot evolved
    if(robot.checkEvolution()){
        cout << "The robot has evolved." << endl;
    }
    else{
        cout << "The robot has NOT evolved." << endl;
    }
    
    return 0;
}