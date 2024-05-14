#include <stdio.h>
#include <stdlib.h>

#define row 5
#define col 5

int main(){
  FILE *fin;
  int input[3];
  float nums[row][col];
  float sum = 0;


  fin = fopen("input.txt", "r");

  if(fin == NULL){
    printf("Files not found");
  }
  // getting data from the input file
  for(int i = 0 ; i < row; i ++){
    for(int j = 0 ; j < col ; j++){
      fscanf(fin, "%f", &nums[i][j]);
    }
  }
  // only display the triangle shape by setting j = i condition, adding each value to sum
  for(int i = 0; i < row ; i++){
    for(int j = i; j < col; j++){
        printf("%f ", nums[i][j]);
        sum += nums[i][j];
    }
    printf("\n");
  }
  printf("\n");
  printf("Sum is %f\n", sum);
  return 0;
}