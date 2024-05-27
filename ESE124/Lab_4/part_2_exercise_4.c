

// LEFT HERE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	// initlize file variable
	int i;
	FILE *fin, *fout;
	// open the file
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	// check if the files exist
	if(fin == NULL || fout == NULL){
		printf("File not found");
		exit(1);
	}
	
	char c = '0';
	// while is not end of the file
	while(c != EOF){
		// read the character
		c = fgetc(fin);
		if(c == EOF){
			break;
		}
		
		
		// check if the condcition the character is +,or- or something, and puts corrsponse string in the file
		if(c == '+'){
			fputs("PLUS ", fout);
		}
		else if(c == '-'){
			fputs("MINUS ", fout);
		}
		
		else if(c == '*'){
			fputs("MULTIPLY ", fout);
		}
		else if(c == '/'){
			fputs("DIVIDE ", fout);
		}
		else if(c == '%'){
			fputs("MODULO ", fout);
		}
		else if(c == '@'){
			fputs("AT ", fout);
		}
		else if(c == '&'){
			fputs("BITWISE AND ", fout);
		}
		else if(c == '^'){
			fputs("BITWISE OR ", fout);
		}
		
		// if is space or next line, just print it as is
		if(c == ' ' || c == '\n'){
			fprintf(fout, "%c", c);
		}

	}
	
	
	return 0;
}
