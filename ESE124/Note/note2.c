#include <stdio.h>
#include <stdlib.h>
#define r 4
#define c 4

int main(){
    FILE *fin;
    float a [r][c];

    fin = fopen("1102.txt", "r");
    if(fin == NULL){
        printf("File not found");
        exit(1);
    }

    for(int i = 0 ; i < r; i++){
        for(int j = 0 ; j < c ; j++){
            fscanf(fin, "%f", &a[i][j]);
        }
    }
    
    
    return 0;
}