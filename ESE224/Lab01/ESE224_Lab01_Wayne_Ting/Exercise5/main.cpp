

#include "MathOperations.h"
#include <iostream>

using namespace std;

int main(){
    MathOperations mathOps;
    
    cout << "Square root of 15 is: " << mathOps.calculateSquareRoot(15) << endl;
    cout << "2 raise to the power of 3: " << mathOps.calculatePower(2, 3) << endl; 
    cout << "Absolute value of -5: " << mathOps.calculateAbsoluteValue(-5) << endl; 

    return 0;
}