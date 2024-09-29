#include "Simulation.h"
#include <fstream>
#include <iostream>
#include "Robot.h"

using namespace std;

Simulation::Simulation(const Robot& rob): robot(rob){

}

void Simulation::loadDataFromFile(const char*filename){
    // open the file
    fstream inputFile(filename);
    if(!inputFile){
        cerr << "Error opening file!" << endl;
    }
    inputFile.close();
    // pass filename to class attribute fname
    fname = filename;
}



void Simulation::run(){
    // open
    fstream inputFile(fname);

    // read a number first
    int num_of_line;
    inputFile >> num_of_line;

    float effect;
    string event;
    // next file read the event
    for(int i = 0 ; i < num_of_line ; i++){
        inputFile >> event >> effect;
        // applied to the robot
        robot.applyEvent(event.c_str(), effect);
        robot.displayStats();
    }

    inputFile.close();
}