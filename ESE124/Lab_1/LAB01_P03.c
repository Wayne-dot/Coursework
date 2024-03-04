//Wayne Ting SBU ID: 115334926

#include <stdio.h>
#include <math.h>

int main(){
	
//	i = # of times that the program loop
	int i = 0;
	
	while(i < 11){
//		intitlize varible
		float x;
		char oper;
		float result;
		
//		get operation
		printf("Enter an operation: ");
		scanf(" %c", &oper);
//		get the floating point number
		printf("Enter a floating point value: ");
		scanf(" %f", &x); 
		
//		do depense what the operation is
		switch (oper) {
			case 'e': result = exp(x); printf("%f\n", result); break;
//			check if x is negative or 0, lnx can't be calculted in these cases
			case '/': if(x <= 0){
				printf("lnx is not defined for non positive x.\n");
			}
			else{
				result = log(x);
				printf("%f\n", result);
			}
			break;
			
			
//			check square root the number is negative, can't be calculated with negative number
			case 'r': if(x < 0){
				printf("Square root is not defined for negative x.\n");
			}
			else{
				result = sqrt(x);
				printf("%f\n", result);
			}
			break;
			
			case 'm': result = abs(x); printf("%f\n", result); break;
			default: printf("invalid operation\n"); break;
		}
		
		i++;
	}
	
}

