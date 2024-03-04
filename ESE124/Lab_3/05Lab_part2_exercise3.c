#include <stdio.h>

int main(){
    char input_char = 'a';
    

    while (input_char != '#')
    {
        printf("Enter a character (# to exit): ");
        scanf("%c", &input_char); getchar();

        if(input_char >= 'A' & input_char <= 'Z'){
            input_char += 32;
        }


        if((input_char >= 'A' & input_char <= 'Z') || (input_char >= 'a' & input_char <= 'z')){
            if(input_char == 'a' || input_char == 'e'|| input_char == 'i' || input_char == 'o' || input_char == 'u'){
                printf("%c is a vowel\n", input_char);
            }
            else{
                printf("%c is a consonant\n", input_char);
            }
        }
        else if(input_char != '#'){
            printf("Invalid input\n");
        }

        
    }

    if(input_char == '#'){
        printf("End of the Program\n");
    }
    
    
    return 0;
}