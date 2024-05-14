#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

int main(){
    char a[MAX];
    printf("Input: ");
    scanf("%s", a);

    printf("Output: \n");
    printf("%s\n", a);

    for(int i = strlen(a) ; i > 0; i--){
        for(int j = 0 ; j < strlen(a); j++){
            a[j] = a[j+1];
        }
        for(int k = 0 ; k < strlen(a); k++){
            printf("%c", a[k]);
        }
        printf("\n");
    }
    return 0;
}