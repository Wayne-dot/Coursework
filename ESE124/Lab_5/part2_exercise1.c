// SBU ID: 115334926

#include <stdio.h>
#include <stdlib.h>

#define MAX 31

int main(){
	// initlize variavle
	float x[MAX];
	FILE *fin;
	float num;
	int i, j;
	float temp;
	
	// open the file
	fin = fopen("input.txt", "r");
	// exit if file not fouind
	if(fin == NULL){
		printf("File not found");
		exit(1);
	}
	// adding each number into the array name x
	i = 0;
	while(fscanf(fin, "%f", &num) != EOF){
		x[i] = num;
		i++;
	}
	
	int counter = i;
	
	// iterateu for each element inside the array
	for(i = 0 ; i <= counter-1; i++){
		// iterate each character if the forward character is less than the character
		for(j = 0; j <= counter - i - 1; j++)
		{
			if(x[j] > x[j+1]){
				temp = x[j+1];
				x[j+1] = x[j];
				x[j] = temp;
			}
		}
	}
	// print out the result
	for(i = 0; i < counter; i++){
		printf("%.2f\n", x[i]);
	}
	
	return 0;
}