#include <stdio.h>

#define PI 3.1415926535

//cos taylor series

int main(){
	float x, a, ans = 1;
	float current;
	int count = 1;
	float b;
	
	printf("Enter the value of x in cos(x) in degrees: ");
	scanf("%f", &x);
	

	b = x * PI/180;
	
	printf("Please enter a precision value for a: ");
	scanf("%f", &a);

	
	current = 1;
	
	while(current > a){
		current = (-current*b*b)/(count*(count+1));
		ans = ans + current;
		count += 2;
	}
	
	printf("Cos(%f) = %f", x, ans);
	
	return 0;
}
