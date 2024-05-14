#include <stdio.h>
#include <stdlib.h>

#define row 5
#define col 5

int main(){
    FILE *fin;
    float nums[row][col];
    float transpose[row][col];
    float result[row][col];
    float temp;

    fin = fopen("input.txt", "r");

    if(fin == NULL){
        printf("Files not found");
    }
    // getting the tranpose matrix
    for(int i = 0 ; i < row; i ++){
        for(int j = 0 ; j < col ; j++){
            fscanf(fin, "%f", &nums[i][j]);
            transpose[j][i] = nums[i][j];
        }
    }
    // first initlize the result matrix place value, then mutiple the matrix valuem using the formula, add them together
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            result[i][j] = 0;
            for(int k = 0 ; k < row ; k++){
                result[i][j] += nums[i][k]*transpose[k][j];
            }
            printf("%f  ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}