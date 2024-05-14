#include <stdio.h>
#include <stdlib.h>

#define row 5
#define col 5

int main(){
    FILE *fin;
    float nums[row][col];
    int m, n;
    float temp;


    fin = fopen("input.txt", "r");

    if(fin == NULL){
        printf("Files not found");
    }

    printf("Input Sequence: ");
    printf("m = ");
    scanf("%d", &m); getchar();
    printf("n = ");
    scanf("%d", &n); getchar();
    // getting data from input file
    for(int i = 0 ; i < row; i ++){
        for(int j = 0 ; j < col ; j++){
            fscanf(fin, "%f", &nums[i][j]);
        }
    }
    // swapping value for m and n row
    for(int i = 0; i < col ; i++){
        temp = nums[m][i];
        nums[m][i] = nums[n][i];
        nums[n][i] = temp;
    }

    // display the value
    for(int i = 0 ; i < row; i ++){
        for(int j = 0 ; j < col ; j++){
            printf("%f ", nums[i][j]);
        }
        printf("\n");
    }



    return 0;
}