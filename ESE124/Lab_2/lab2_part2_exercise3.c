#include <stdio.h>

int main(){
	
	unsigned char a;
	unsigned char b;
	
	int p, n;
	
	// on my local computer, %hhx does not work for me, but it works for online C compiler
	printf("input first hexadecimal number: ");
	scanf(" %hhx", &a);
	
	printf("input second hexadecimal number: ");
	scanf(" %hhx", &b);
	
	printf("p = ");
	scanf(" %d", &p);

	printf("n = ");
	scanf(" %d", &n);

	
    
	
	unsigned char mask1 = 0xff;
    mask1  = mask1 << (8-n);
    mask1 = mask1 >> (7-p);
	mask1 = ~mask1;

	a = a & mask1;

	unsigned char mask2 = 0xff;
	mask2 = mask2 >> (8-n);

	b = b & mask2;
	b = b << (p-1);

	a = a | b;

	printf("%x\n", b);
	printf("%x\n", a);
	
	return 0;
}

