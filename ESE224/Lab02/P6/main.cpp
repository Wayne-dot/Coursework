
#include <iostream>
#include "FizzBuzz.h"

using namespace std;

int main(){

    int start, end, fizzNum, buzzNum;

    cout << "Enter the starting number: ";
    cin >> start;
    cout << "Enter the ending number: ";
    cin >> end;
    cout << "Enter the number for 'Fizz': ";
    cin >> fizzNum;
    cout << "Enter the number for 'Buzz': ";
    cin >> buzzNum;

    FizzBuzz fizzbuzz;
    fizzbuzz.run(start, end, fizzNum, buzzNum);

    return 0;
}