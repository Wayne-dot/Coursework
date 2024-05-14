#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fin, *fout;
	char c, next;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	
	if(fin == NULL){
		printf("Found not found");
	}
	
	c = fgetc(fin);
	
	while(c != EOF){
		next = fgetc(fin);
		
		
		if(c == next){
			fputc(c, fout);
		}
		else{
			ungetc(next, fin);
			fputc(c, fout);
		}
		c = fgetc(fin);
	}
	
	return 0;
}
