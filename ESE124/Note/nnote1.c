#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int main(){
    FILE *fin;
    int val_digit; 
    int n = 0;
    float sum = 0;
    int i;
    fin = fopen("1102.txt", "r");

    if(fin == NULL){
        printf("File not found");
        exit(1);
    }

    // fscanf / fgetc / fgets
    // fscanf = string level
    char str[MAX];

    while((fscanf(fin, "%s", str)) != EOF){


        if(str[0] >= '0' && str[0] <= '9'){
            // printf("%s ", str);
            i = 0;
            val_digit = 0;
            while(str[i] != '\0'){
                val_digit = val_digit * 10 + (str[i] - '0');
                i++;
            }
            sum += val_digit;
            n++;
        }
        
    }

    if(n != 0){
        printf("Average: %.2f\n", sum/n);
    }

    
    return 0;
}