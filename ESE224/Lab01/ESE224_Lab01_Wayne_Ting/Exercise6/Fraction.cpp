

#include "Fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction(): numerator(0), denominator(1){

}

// If the denominator is 0, set it to 1 and print an error message
Fraction::Fraction(int num, int demon): numerator(num), denominator(demon){
    if(demon == 0){
        cout << "Denominator can not be zero" << endl;
        demon = 1;
    }
}

int GCD(int num_1, int num_2){ 
     if(num_2 == 0){
        return num_1;
     }
     return GCD(num_2, num_1 % num_2);
}

void Fraction::print(){
    cout << "Current Fraction Result: " << numerator << "/" << denominator << endl;
}

Fraction Fraction::simplify(){
    int largest_common_divisor = GCD(numerator, denominator);
    numerator /= largest_common_divisor;
    denominator /= largest_common_divisor;

    if(denominator < 0){
        numerator = -numerator;
        denominator = -denominator;
    }

    return Fraction(numerator, denominator);
}

Fraction Fraction::add(const Fraction& other){
    int common_demon = denominator*other.denominator;

    int new_num_1 = numerator * other.denominator;
    int new_num_2 = other.numerator * denominator;

    int new_num = new_num_1 + new_num_2;
    
    numerator = new_num;
    denominator = common_demon;

    Fraction final = simplify();
    
    return final;
}

Fraction Fraction::subtract(const Fraction& other){
    int common_demon = denominator*other.denominator;

    int new_num_1 = numerator * other.denominator;
    int new_num_2 = other.numerator * denominator;

    int new_num = new_num_1 - new_num_2;
    
    numerator = new_num;
    denominator = common_demon;

    Fraction final = simplify();
    
    return final;
}

Fraction Fraction::multiply(const Fraction& other){
    int new_denom = denominator * other.denominator;
    int new_num = numerator * other.numerator;

    Fraction final(new_num, new_denom);
    
    return final.simplify();
}

Fraction Fraction::divide(const Fraction& other){
    if(other.numerator == 0){
        cout << "Can not divide zero" << endl;
        return Fraction(0, 1);
    }

    int new_num = numerator * other.denominator;
    int new_denom = denominator * other.numerator;

    Fraction final(new_num, new_denom);
    return final.simplify();

}