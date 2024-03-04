// Wayne Ting SBU ID: 115334926

#include <stdio.h>
#include <stdlib.h>

int main(){
	// initlize pointer for the file
	FILE *fin, *fout;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	
	// check if the filex exist
	if(fin == NULL || fout == NULL){
		printf("File not found");
		exit(1);
	}
	
	char c = '0';
	
//	junk charater
//if fscanf() == 1

	// initlize identity and space
	int iden = 0;
	int space = 0;
	
	while(c != EOF){
		
		c = fgetc(fin);
		if(c == EOF){
			break;
		}
		
		// check if is a alphabet and underscore
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_'){
			fprintf(fout, "%c", c);
			iden = 1;
			space = 0;
		}
		// check if is next line
		else if(c == '\n'){
			fprintf(fout, "%c", c);
			iden = 0;
			space = 1;
		}
		// check if is space
		else if(c == ' '){
			if(space == 0){
				fprintf(fout, "%c", c);
			}
			iden = 0;
		}
		// check if is number
		else if(c >= '0' && c <= '9'){
			if(iden == 1){
				fprintf(fout, "%c", c);
			}
		}

	}
	
	
	return 0;
}
