// Wayne Ting SBU ID: 115334926

#include <stdio.h>
#include <stdlib.h>

int main(){
    // initlize file variable
    FILE *fin, *fout;
    // open the file
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    // check if the files exist
    if(fin == NULL || fout == NULL){
        printf("File not found");
        exit(1);
    }

    char character;
    char next_character;
    // while is not end of the file
    while (character != EOF)
    {
        character = fgetc(fin);

        if(character == EOF){
            break;
        }

        next_character = fgetc(fin);
        ungetc(next_character, fin);
        // check if the condcition the character is +,or- or something, and puts corrsponse string in the file
        if(character == '+'){
            // check if the next character is also +
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
            // check if the next character is also -
            if(next_character == '-'){
                fputs("(DECREMENT) ", fout);
                fgetc(fin);
            }
            else{
                fputs("MINUS ", fout);
            }
			
		}
		
		else if(character == '*'){
            // check if the next character is =
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
        else if(character == '='){
            // check if the next character is also =
            if(next_character == '='){
                fputs("(EQUAL) ", fout);
                fgetc(fin);
            }
            else{
                fputs("(ASSIGN) ", fout);
            }
            
        }


        // if is space or next line, just print it as is
        if(character == ' ' || character == '\n'){
			fprintf(fout, "%c", character);
		}
        
    }

    // close the file

    fclose(fin);
    fclose(fout);
    
    
    return 0;
}