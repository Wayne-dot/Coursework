

#include <stdio.h>
#include <stdlib.h>

int main(){
	// initlize pointer for input and output file
	FILE *fin, *fout;
	// open files
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	
	// check if files exist
	if(fin == NULL || fout == NULL){
		printf("File not found");
		exit(1);
	}
	
	char c = '0';
	
//	junk charater
//if fscanf() == 1
	
	// while is not reach the end of the file
	while(c != EOF){
		// read a character
		c = fgetc(fin);
		// break if is end of the file
		if(c == EOF){
			break;
		}
		// write it at the output file
		fprintf(fout, "%c", c);
	}
	
	
	return 0;
}
