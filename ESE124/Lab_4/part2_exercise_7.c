

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
	
	char character = '0';
	char next_character;
	
//	junk charater
//if fscanf() == 1
	int iden = 0;
	int space = 0;
	
	while(character != EOF){
		
		character = fgetc(fin);
		if(character == EOF){
			break;
		}
		next_character = fgetc(fin);
        ungetc(next_character, fin);
		
		if((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || character == '_'){
			// convert to uppercase if the character is lowercase
			if((character >= 'a' && character <= 'z')){
				character -= 32;
			}
			fprintf(fout, "%c", character);
			iden = 1;
			space = 0;
		}
		
		// check if the condcition the character is +,or- or something, and puts corrsponse string in the file
        // check if the next character is certain chracter, print out special character if it is, otherwise, printout normal character
        else if(character == '+'){
            if(next_character == '+'){
                fputs("(INCREMENT) ", fout);
                fgetc(fin);
            }
            else if(next_character == '='){
                fputs("(ADD ASSIGN) ", fout);
                fgetc(fin);
            }
            else{
                fputs("PLUS ", fout);
            }
        }

        else if(character == '-'){
            if(next_character == '-'){
                fputs("(DECREMENT) ", fout);
                fgetc(fin);
            }
            else{
                fputs("MINUS ", fout);
            }
			
		}
		
		else if(character == '*'){
            if(next_character == '='){
                fputs("(MULTIPLY ASSIGN) ", fout);
                fgetc(fin);
            }
            else{
                fputs("MULTIPLY ", fout);
            }
		}
		else if(character == '/'){
			fputs("DIVIDE ", fout);
		}
		else if(character == '%'){
			fputs("MODULO ", fout);
		}
		else if(character == '@'){
			fputs("AT ", fout);
		}
		else if(character == '&'){
			fputs("BITWISE AND ", fout);
		}
		else if(character == '^'){
			fputs("BITWISE OR ", fout);
		}
        else if(character == '.'){
            fputs("(DOT) ", fout);
        }
        else if(character == ','){
            fputs("(COMMA) ", fout);
        }
        
        else if(character == ';'){
            fputs("(SEMICOLON) ", fout);
        }

        else if(character == ':'){
            fputs("(COLON) ", fout);
        }

        else if(character == '='){
            if(next_character == '='){
                fputs("(EQUAL) ", fout);
                fgetc(fin);
            }
            else{
                fputs("(ASSIGN) ", fout);
            }
            
        }

		// if next line character, set iden to 0 and space to 1
		if(character == '\n'){
			fprintf(fout, "%c", character);
			iden = 0;
			space = 1;
		}
		// only when space is 0 print the space
		if(character == ' '){
			if(space == 0){
				fprintf(fout, "%c", character);
			}
			iden = 0;
		}
		// only when iden is 1 print the number
		if(character >= '0' && character <= '9'){
			if(iden == 1){
				fprintf(fout, "%c", character);
			}
		}


	}
	
	
	return 0;
}
