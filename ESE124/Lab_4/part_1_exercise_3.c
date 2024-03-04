// Wayne Ting SBU ID: 115334926

#include <stdio.h>
#include <stdlib.h>

int main(){
	// initlize the pointer for the files
	FILE *fin, *fout;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	
	if(fin == NULL || fout == NULL){
		printf("File not found");
		exit(1);
	}
	
	char c = '0';
	
//	junk charater
//if fscanf() == 1
	int iden = 0;
	int space = 0;
	
	while(c != EOF){
		
		c = fgetc(fin);
		if(c == EOF){
			break;
		}
		
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_'){
			// convert to uppercase if the character is lowercase
			if((c >= 'a' && c <= 'z')){
				c -= 32;
			}
			fprintf(fout, "%c", c);
			iden = 1;
			space = 0;
		}
		// if next line character, set iden to 0 and space to 1
		else if(c == '\n'){
			fprintf(fout, "%c", c);
			iden = 0;
			space = 1;
		}
		// only when space is 0 print the space
		else if(c == ' '){
			if(space == 0){
				fprintf(fout, "%c", c);
			}
			iden = 0;
		}
		// only when iden is 1 print the number
		else if(c >= '0' && c <= '9'){
			if(iden == 1){
				fprintf(fout, "%c", c);
			}
		}

	}
	
	
	return 0;
}
