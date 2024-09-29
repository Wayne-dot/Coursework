
#include <iostream>
#include "FizzBuzz.h"

using namespace std;


void FizzBuzz::run(int start, int end, int fizzNum, int buzzNum){

    if(start > end){
        cout << "Starting number can not be larger than ending number" << endl;
        return ;
    }

    if(fizzNum == 0 || buzzNum == 0){
        cout << "fizzNum or buzzNum cannot be zero" << endl;
        return ;
    }

    for(int i = start ; i <= end ; i++){
        if(i % fizzNum == 0 && i % buzzNum == 0){
            cout << "FizzBuzz";
        }
        else{
            if(i % fizzNum == 0){
                cout << "Fizz";
            }
            else if (i % buzzNum == 0) {
                cout << "Buzz";
            }
            else{
                cout << i;
            }
        }

        cout << endl;
    }
}