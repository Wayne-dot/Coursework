#include <stdio.h>
#include <string.h>

int Mystrcmp(char s1[], char s2[]){
    if(strlen(s1) != strlen(s2)){

    }
    else{
        for(int i = 0 ; i < strlen(s1) ; i++){
            if(s1[i] < s2[i]){
                return -1;
            }
            else if(s1[i] > s2[i]){
                return 1;
            }
        }
    }
}