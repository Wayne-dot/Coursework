
#include <iostream>

using namespace std;

bool isPrime(int num){
    // all prime number is in the form of 6k + 1 or 6k - 1, where k >= 1. except for 2, 3, they are prime number
    // so 5, 7  11, 13  ......more pairs
    if (num <= 1){
        return false;
    }
    if (num <= 3){
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0){
        return false;
    }

    // checking the condition of 6k + 1 or 6k - 1
    for(int i = 5 ; i*i <= num ; i+= 6){
        if(num % i == 0 || num % (i+2) == 0){
            return false;
        }
    }
    
    return true;
}

int main(){
    
    int number;

    for(;;){
        cout << "Enter a number (0 to exit): ";
        cin >> number;

        if(number == 0){
            cout << "Exiting..." << endl;
            break;
        }

        if(isPrime(number)){
            cout << number << " is a prime number." << endl;
        }
        else{
            cout << number << " is not a prime number." << endl;
        }

    }
    return 0;
}