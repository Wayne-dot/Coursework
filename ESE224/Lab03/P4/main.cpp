#include <iostream>
#include "StudentGradeProcessor.h"

using namespace std;

int main(){

    StudentGradeProcessor processor;

    string inputFilenName, outputFileName;

    cout << "Enter the input file name: ";
    cin >> inputFilenName;
    cout << "Enter the output file name: ";
    cin >> outputFileName;

    processor.processFile(inputFilenName.c_str(), outputFileName.c_str());

    cout << "Grade report generated successfully!" << endl;

    return 0;
}