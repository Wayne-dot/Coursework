#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// reverse the string

int main(){
    char s[10] = "abcde";
    char *cptr, *last, temp;

    cptr = s;
    last = s;
    last += strlen(s) - 1;

    for(int i = 0 ; i < strlen(s) / 2; i++){
        temp = *cptr;
        *cptr = *last;
        *last = temp;
        cptr++;
        last--;
    }

    cptr = s;
    for(int i = 0 ; i < strlen(s) ; i++){
        printf("%c", *cptr);
        cptr++;
    }

    return 0;
}