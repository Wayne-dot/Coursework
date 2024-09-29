

#include <iostream>
#include "PalindromeChecker.h"

using namespace std;

int main(){
    int number;

    cout << "Enter a number to check if it's a palidrome: ";
    cin >> number;

    PalidromeChecker checker;

    if(checker.isPalindrome(number)){
        cout << number << " is a palindrome!" << endl;
    }
    else{
        cout << number << " is not a palindrome." << endl;
    }
    
    return 0;
}
