#include <stdio.h>

int main(){
	int n;
	int muti = 1;
	int final = 0;
	int i;
	
	printf("Input n: ");
	scanf("%d", &n);

	
	for(i = 1; i < n+1; i++){
		final += 9*muti;
		muti *= 10;
	}
	
	if(final < 0){
		printf("Overflow");
	}
	
	printf("Output is %d", final);
	
	

	
	return 0;
}
