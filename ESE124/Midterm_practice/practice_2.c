// Write a program in C to display the following pattern. The number of rows is an input to the
// program:
// ___1___, 3
// __2_3__, 2
// _4_5_6_, 1
// 7 8 9 10, 0


#include <stdio.h>

int main(){
    int row;
    int count = 1;
    printf("Numer of row: ");
    scanf("%d", &row);

    for(int i = 1; i <= row; i++){
        for(int k = 1; k <= row-i; k++){
            printf(" ");
        }

        

        for(int j = 1; j <= i; j++){
            printf("%d ", count);
            count += 1;
        }

        for(int k = 1; k <= row-i; k++){
            printf(" ");
        }

        printf("\n");
    }
    
    return 0;
}