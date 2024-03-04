// Wayne Ting SBU ID: 115334926

#include <stdio.h>

int main(){
	// show different size of the data type in terms of bytes
	printf("unsigned char is %d byte\n", sizeof(unsigned char));  
	printf("unsigned short is %d byte\n", sizeof(unsigned short)); 
	printf("unsigned int is %d byte\n", sizeof(unsigned int));  
	printf("unsigned long is %d byte \n", sizeof(unsigned long)); 

	printf("\n");
	
	unsigned char e;
	
	printf("input hexadicmal number: ");
	scanf("%hhx", &e);
	
	printf("Hexadecimal is 0x%x\n", e); 
	printf("Decimal is %d\n", e);    
	printf("If exist, the associated character is %c\n", e);   

	// %x show the hexdecimal number, %d show the decimal number, %c show the character associated with the hexadecimal if is avaliable on the ASCII table 
	
	printf("\n");
	
	
	unsigned char a = 0x12;
	unsigned char b = 0xda;
	unsigned char c = 0x3b;
	unsigned char d = 0xbe;
	
	unsigned char f;
	
	f = a & b;
	printf("0x%x\n", f);
	
	f = a | b;
	printf("0x%x\n", f);
	
	f = a ^ b;
	printf("0x%x\n", f);
	
	
	f = c & d;
	printf("0x%x\n", f);
	
	f = c | d;
	printf("0x%x\n", f);
	
	f = c ^ d;
	printf("0x%x\n", f);
	
	printf("\n");
	
	
	unsigned char g;
	
	printf("input hexadicmal number: 0x");
	scanf("%x", &g);
	
	unsigned char h = 0x0f;
	
	g = g | h;
	printf("Result: 0x%x", g);


	return 0;
}

