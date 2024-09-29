
#include <iostream>
#include "Fraction.h"

using namespace std;

int main(){
    Fraction sugar(1, 2);  //1/2
    Fraction serving(6, 4); //6/4 ratio


    Fraction scaledSugar = sugar.multiply(serving);
    scaledSugar.simplify();

    cout << "Scaled amount of sugar for 6 serving: ";
    scaledSugar.print();

    return 0;
}