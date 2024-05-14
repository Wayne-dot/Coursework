#include <stdio.h>

#define MAX 60

int main(){
	int a[MAX];
	int num;
	int i = 0;
	FILE *fin;
	fin = fopen("input.txt", "r");
	
	if(fin == NULL){
		printf("Found not found");
	}
	
	
	while(fscanf(fin, "%d", &num) != EOF){
		a[i] = num;
		i ++;
	}
	
	int counter = i;
	printf("Coubter is %d\n", counter);
	
	int max = a[0];
	
	for(i = 0; i < counter; i++){
		printf("%d\n", a[i]);
		if (a[i] > max)
			max = a[i];
	}
	printf("\n");
	
	printf("Max is %d", max);
	return 0;
}
