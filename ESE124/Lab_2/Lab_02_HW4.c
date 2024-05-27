

#include <stdio.h>

// counts the number of leading bits 0 in a binary number of length 4 bytes
// assuming if F1F1F1F1
// 1111 0001 1111 0001 1111 0001 1111 0001
// result should be 4, since four 0 leading bits

int main(){
    unsigned int a; 
    int zero = 0;

    printf("Enter a 32 bit Hexadecimal value: ");
    scanf("%x", &a);

    for(int i = 0; i < (sizeof(unsigned int) * 8); i+=4){
        // get the most significal bits, ....1000, ....1000 0000, so on, shifting to left every iteration
        unsigned int mask = 1 << i+3;
        // if the leading bits is zero
        if(!(a & mask)){
            zero++;
        }
    }

    printf("Number of leading zeros are: %d", zero);
    
    return 0;
}