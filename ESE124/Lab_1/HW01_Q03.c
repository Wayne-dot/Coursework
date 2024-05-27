

#include <stdio.h>

//Devise a C program that reads integer numbers from the keyboard until the value 0 is entered. Compute and display the sum of even numbers and separately, compute and display the sum of odd numbers

int main(){
//	initlize variable
	int sum_odd = 0;
	int sum_even = 0;
	int num;
	
//	do until the input value is 0
	do {
		printf("Input: ");
		scanf("%d", &num);
		
//		if the value is 0, return 0
		if (num == 0){
			return 0;
		}
		
//		if the input is even add to sum even
		if (num % 2 == 0){
			sum_even += num;
			printf("Sum of even: %d\n", sum_even);
		}
//		otherwise, add the sum add
		else{
			sum_odd += num;
			printf("Sum of odd: %d\n", sum_odd);
		}
		
	}
	while(num!=0);
	
	return 0;
}
