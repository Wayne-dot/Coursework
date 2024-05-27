

#include <stdio.h>

// counts the number of bits 1 and separately the number of bits 0 in a binary number of length 4 bytes.

int main(){
    unsigned int a;
    int one = 0;
    int zero = 0;

    printf("Enter a 32 bit Hexadecimal value: ");
    scanf("%x", &a);

    for(int i = 0 ; i < sizeof(unsigned int) * 8; i++){
        // ...0001
        // ...0010
        // get the bit we care about by using AND
        unsigned int mask = 1 << i;
        // !! convert to 0 and 1
        if(!!(a & mask)){
            one++;
        }
        else{
            zero++;
        }
        
    }

    printf("Number of ones: %d\n", one);
    printf("Number of zeros: %d\n", zero);


    return 0;
}