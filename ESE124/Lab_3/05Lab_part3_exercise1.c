#include <stdio.h>

int main(){
	float x, a, ans = 0.0;
	float current;
	int count = 1;
	
	printf("Please enter a value for x: ");
	scanf("%f", &x);
	
	
	printf("Please enter a precision value for a: ");
	scanf("%f", &a);
	
	float res = 1/(1-x);
	
	current = 1/x;
	
	while(current*x > a){
		
		current = current * x;
		ans = ans + current;
		printf("Taylor Series 1 / (1 - x) %dth Order Sum = %f\n", count, ans);
		count += 1;
	}
	
	printf("Final result %f", res);
	
	return 0;
}
