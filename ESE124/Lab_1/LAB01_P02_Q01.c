

#include <stdio.h>
#include <math.h>

int main() {
	
//	intitlize sum to 0, since the minium sum can get is 0
	double sum = 0;
	printf("Enter the floating-point numbers(type any non-numeric character to finish)\n");
	
	float num2;
	printf("Input: ");
	scanf("%f", &num2);
	sum += num2;
	
	
	while(1){
//		initlize the input number as float, since is deciaml
		float num;

		printf("Input: ");
		
//		get the input
		if (scanf("%f", &num) == 1){
	//		add the input to the sum
			sum += num;
	//		output the current sum that is after added
			printf("Output: Sum = ");
			printf("%.3f\n", sum);	
		}
		
		
		else{
			return 0;
		}
		 
	}
	
}
