// Write a program in C to display the following pattern. The number of rows is an input to the
// program:
// 1
// 2 3
// 4 5 6
// 7 8 9 10


#include <stdio.h>

int main(){
    int row;
    int count = 1;
    printf("Numner of row: ");
    scanf("%d", &row);

    for(int i = 1 ; i <= row ; i++){
        for(int j = 1; j <= i; j++){
            printf("%d ", count);
            count += 1;
        }
        printf("\n");
    }
    
    return 0;