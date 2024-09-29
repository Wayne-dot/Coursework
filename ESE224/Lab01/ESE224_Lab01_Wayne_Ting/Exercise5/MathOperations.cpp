

#include <iostream>
#include "MathOperations.h"
#include <cmath>

using namespace std;

double MathOperations::calculateSquareRoot(double number){
    if(number < 0){
        cout << "Negative number can not be square root" << endl;
    }
    if(number == 0){
        return 0;
    }
    return sqrt(number);
}

double MathOperations::calculatePower(double base, double exponent){
    return pow(base, exponent);
}

double MathOperations::calculateAbsoluteValue(double number){
    if(number == 0){
        return 0;
    }
    return abs(number);
}

