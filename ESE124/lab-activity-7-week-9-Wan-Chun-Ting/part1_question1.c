#include <stdio.h>
#include <stdlib.h>

#define row 5
#define col 5

int main()
{
  FILE *fin;
  int input[3];
  float nums[row][col];
  float sum = 0.0;
  int n;

  fin = fopen("input.txt", "r");

  if(fin == NULL){
    printf("Files not found");
  }

  printf("Input Sequence: ");

  scanf("%d %d %d", &input[0], &input[1], &input[2]);
  // getting data from input file
  for(int i = 0 ; i < row; i ++){
    for(int j = 0 ; j < col ; j++){
      fscanf(fin, "%f", &nums[i][j]);
    }
  }
  // summing up only row of the user input
  for(int i = 0 ; i < 3 ; i++){
    n = input[i];
    for(int j = 0 ; j < col ; j++){
      sum += nums[n][j];
    }
  }
  // display the sum
  printf("Sum is %f\n", sum);


}
