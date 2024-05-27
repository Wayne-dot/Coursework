

#include <stdio.h>


// reads one hexadecimal number from the keyboard (using scanf %x) and 
// then sets the most significant p bits of the number to 0 and the least significant 8 - p bits to 1. 
// The resulting value is displayed using printf %x. The value of variable p is read from the keyboard and is between 0 and 8.

// 0011 0111, p = 5, 8 - 5 = 3
// 00(1)1 (0)111

// and mask1 = 1101 1111
// or mask2 = 0000 1000

// Final output: 00(0)1 (1)111


int main(){
    unsigned char a;
    int p;

    printf("Enter a hexadecimal number: ");
    scanf("%hhx", &a);

    printf("Enter a value for P: ");
    scanf("%d", &p);

    // step to make mask1 = 1101 1111
    // 0000 0001
    // 0010 0000
    // 1101 1111
    unsigned char mask1 = 0x01;
    mask1 = ~(mask1 << p);
    a = a & mask1;

    // step to make mask2 = 0000 1000
    // 0000 0001
    // 0000 1000
    unsigned char mask2 = 0x01;
    mask2 = mask2 << 8-p;
    a = a | mask2;


    printf("%x", a);

    
    
    return 0;
}