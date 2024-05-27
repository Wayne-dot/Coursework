

#include <stdio.h>

int main(){

	// itnilize variable
	
	unsigned int a;
	int p, n;
	

	// getting input
	printf("input a hexadecimal number: ");

	scanf("%hhx", &a);getchar();

	printf("p = ");
	scanf("%d", &p);getchar();
	
	printf("n = ");
	scanf("%d", &n); getchar();
	
	
	// getting the bit size of unsigned int
	int intsize = sizeof(unsigned int)*8;
	
	// shfiting, reuqired more shift since using unsigned int
	a  = a << (31-p);
	a = a >> (32-n);
	printf("0x%x", a);

	return 0;
}


