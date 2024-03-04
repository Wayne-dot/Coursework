#include <stdio.h>

int main(){
	
	
	while(1){
		unsigned char second;
		unsigned char first;
		unsigned char output;
		char oper;
		
		printf("Enter the first hex value: 0x");
		scanf("%hhx", &first); getchar();
		
		printf("Enter the second hex value: 0x");
		scanf("%hhx", &second); getchar();
		
		printf("Enter the bitwise operator & - Bitwise AND, | - Bitwise OR, ^ - Bitwise XOR: ");
		scanf("%c", &oper); getchar();
		
		if(oper == '&'){
			output = first & second;
		}
		else if(oper == '|'){
			output = first | second;
		}
		else if(oper == '^'){
			output = first ^ second;
		}
		
		printf("Output: 0x%hhx\n", output);	
	}
	
	
	return 0;
}
