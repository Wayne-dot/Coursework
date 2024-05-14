#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fin;
	fin = fopen("input.txt", "r");
	int num, num_char;
	char c;
	
	
	if(fin == NULL){
		printf("File not found");
		exit(1);
	}
	
	c = fgetc(fin);
	
	while(c != EOF){
		if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
			num_char+=1;
		}
		else{
			num+=1;
		}
		c = fgetc(fin);
	}
	
	
	if(num_char > num*2){
		printf("This is a sparse array");
	}
	else{
		printf("This is not a sparse array");	
	}
	
	return 0;
}
