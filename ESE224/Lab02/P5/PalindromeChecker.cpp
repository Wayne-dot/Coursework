
#include "PalindromeChecker.h"

bool PalidromeChecker::isPalindrome(int num){

    int reverse_number = 0;
    int original = num;
    int digit;
    int temp = num;

    while(temp != 0){
        digit = temp % 10;
        reverse_number = reverse_number * 10 + digit;
        temp /= 10;
    }

    return num == reverse_number;

}
