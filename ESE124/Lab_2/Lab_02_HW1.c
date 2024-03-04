// Wayne Ting SBU ID: 115334926

#include <stdio.h>

// reads one hexadecimal number from the keyboard (using scanf %x) and then sets the most significant 2 bits of the number to 00 and the least significant 2 bits to 11. 
// The resulting value is displayed using printf %x.

// a = (10)01 00(01)

// for first two bit
// a << 2, >> 2, (00)01 0001

// for the last two bit
// maks1 = 0000 0011
// a or mask1 = 0001 0011

// Final output = (00)01 00(11)

int main(){
    unsigned char a;

    printf("Enter a hexadecimal number: ");
    scanf("%hhx", &a);

    a <<= 2;
    a >>=2;

    unsigned char mask = 0xff;
    mask = ~(mask << 2);

    a = a | mask;
    printf("%x\n", a);
    return 0;
}