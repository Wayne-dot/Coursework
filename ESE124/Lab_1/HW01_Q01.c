

#include <stdio.h>

//Devise the following C program: It reads three numbers from the keyboard, then sorts them in increasing order of their values, and then displays these numbers in their ascending order.

int main(){
//	intitlize three input number
	long num1;
	long num2;
	long num3;
	
//	get all three input number
	printf("Enter first number: ");
	scanf("%d", &num1);
	
//	setting min, mid and max to num1
	long min = num1;
	long mid = num1;
	long max = num1;
	
	printf("Enter second number: ");
	scanf("%d", &num2);
	
	printf("Enter third number: ");
	scanf("%d", &num3);
	
//	check if num2 place in min, mid or max
	if (num2 < min){
		min = num2;
	}
	else if(num2 > max){
		max = num2;
	}
	else{
		mid = num2;
	}
	
//	check if num3 place in min, mid, max
	if(num3 < min){
		min = num3;
	}
	else if(num3 > max){
		max = num3;
	}
	else{
		mid = num3;
	}
	
//	print out result
	printf("Ascending order of those three numbers are: %d %d %d", min, mid, max);
		
	return 0;
}
