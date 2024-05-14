#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

int main(){
    char str1[MAX], str2[MAX];
    int k;
    printf("s1: ");
    scanf("%[^\n]", str1); getchar();

    printf("s2: ");
    scanf("%[^\n]", str2); getchar();

    for(int i = 0 ; i < strlen(str2) ; i++){
        for(int j = 0 ; j < strlen(str1) ; j++){
            if(str2[i] == str1[j]){
                for(k = j ; k < strlen(str1) - 1 ; k++){
                    str1[k] = str1[k+1];
                }
                str1[k] = '\0';
            }
        }
    }
    printf("\n%s\n", str1);
    
    return 0;
}
