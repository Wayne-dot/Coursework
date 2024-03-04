// Wayne Ting SBU ID: 115334926

#include <stdio.h>

int main(){

	// intitlize variable
	unsigned char a;
	int p, n;
	
	// getting input
	printf("input a hexadecimal number: ");

	scanf("%hhx", &a);getchar();

	printf("p = ");
	scanf("%d", &p);getchar();
	
	printf("n = ");
	scanf("%d", &n);getchar();

	// perform shifting
	a  = a << (7-p);
	a = a >> (8-n);

	// display output
	printf("0x%x", a);

	return 0;
}