#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[20], *p;

    printf("Input about 10 character of string\n");
    scanf("%s", str);

    // pointer refer to the adress of the string
    p = str;

    for(int i = 0 ; i < strlen(str) ; i++){
        for(char *j = p ; *j != '\0' ; j++){
            printf("%c", *j);
        }
        printf("\n");
        // shift to the right
        p++;
    }

    return 0;
}