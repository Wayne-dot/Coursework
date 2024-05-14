#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_isalpha(char ch){
    // 1 if the input is a alphabet
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int my_isdigit(char d){
    return (d >= '0' && d <= '9');
}

int my_is_upper(char ch){
    return (ch >= 'A' && ch <= 'Z');
}

int my_to_upper(char ch){
    if(ch >= 'a' && ch<= 'z'){
        return ch -= ('a' - 'A');
    }
    else{
        return ch;
    }
}

int my_to_lower(char ch){
    if(ch >= 'A' && ch<= 'Z'){
        return ch += ('a' - 'A');
    }
    else{
        return ch;
    }
}



int main(){
    char ch = 'E';
    printf("Check if is alphabet result for %c is %d\n", ch, my_isalpha(ch));
    ch = '4';
    printf("Check if is alphabet result for %c is %d\n", ch, my_isalpha(ch));
    
    ch = '3';
    printf("Check if is digit result for %c is %d\n", ch, my_isdigit(ch));
    ch = 'h';
    printf("Check if is digit result for %c is %d\n", ch, my_isdigit(ch));
    
    ch = 'H';
    printf("Check if is upper case result for %c is %d\n", ch, my_is_upper(ch));
    ch = 'd';
    printf("Check if is upper case result for %c is %d\n", ch, my_is_upper(ch));

    ch = 'p';
    printf("Funciton to upper case result, if lower, convert to upper, for %c is %c\n", ch, my_to_upper(ch));
    ch = '4';
    printf("Funciton to upper case result, if lower, convert to upper, for %c is %c\n", ch, my_to_upper(ch));

    ch = 'T';
    printf("Funciton to lower case result for %c is %c\n", ch, my_to_lower(ch));
    ch = 'h';
    printf("Funciton to lower case result for %c is %c\n", ch, my_to_lower(ch));
    
    return 0;
}
