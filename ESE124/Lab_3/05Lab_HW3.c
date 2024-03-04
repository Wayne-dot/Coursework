#include <stdio.h>


// Design a C program to convert a binary number into a decimal value. Use hexadecimals to
// input the binary number. What is the largest binary number that your program can convert? Example:
// Input the number 0101 0101 (0x55). Output the equivalent decimal number 85


int main(){
    unsigned char in_bin;
    unsigned char temp, mask = 0x01;

    int final = 0, mutiplier = 1;
    int new;

    printf("Enter binary number as hexadecimal: 0x");
    scanf("%hhx", &in_bin);

    for(int i = 0; i < 8; i++){
        temp = (in_bin >> i) & mask;

        if(temp & mask){
            final += mutiplier;
        }

        mutiplier *= 2;
    }
    
    printf("Output: %d", final);
    return 0;
}