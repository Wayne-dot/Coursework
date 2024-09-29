
#include "StudentGradeProcessor.h"
#include <fstream>
#include <iostream>
#include <ostream>

using namespace std;

void StudentGradeProcessor::processFile(const char* inputFileName, const char* outputFileName){
    ifstream inputfile(inputFileName);
    ofstream outputfile(outputFileName);

    if(!inputfile || !outputfile){
        cout << "File can not be open" << endl;
    }

    string name;
    int score;
    char grade;

    while(inputfile >> name >> score){
        if(name == "-1"){
            break;
        }
        
        switch (score / 10) {
            case 10:
            case 9:
                grade = 'A';
                break;
            case 8:
                grade = 'B';
                break;
            case 7:
                grade = 'C';
                break;
            case 6:
                grade = 'D';
                break;
            default:
                grade = 'F';
                break;
        }
        outputfile << name << ": " << grade << endl;
    }

    inputfile.close();
}