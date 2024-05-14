#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// determine the decimal place
// get the integer value
// get the decimal value

int main()
{
  FILE *fin, *fout;
  char str[MAX];
  float nums[MAX];
  int decimal_place, k = 0;
  float num = 0.0, muti = 1.0, x = 1.0, sum = 0.0;

  fin = fopen("input.txt", "r");
  fout = fopen("output.txt", "w");
  

  if(fin == NULL || fout == NULL){
    printf("File not found");
    exit(1);
  }

  fprintf(fout, "Values are: ");
  
  while((fscanf(fin, "%s", str)) != EOF){
    // detect the decimal place location
    for(int i = 0; i < strlen(str); i++){
      if(str[i] == '.'){
        decimal_place = i;
      }
    }
    // -1 to the decimal place if there is sign
    if(str[0] == '-' || str[0] == '+'){
      decimal_place -= 1;
    }

    // getting the maximum mutiplier
    for(int i = 1; i <= decimal_place - 1; i++){
      muti *= 10;
    }
    // iterate through the string, if it is a number, mutiply with the mutillier, reduce muti by a factor of 10
    for(int i = 0 ; i < strlen(str); i++){
      if(str[i] >= '0' && str[i] <= '9'){
        x = str[i] - '0';
        num += x * muti;
        muti *= 0.1;
      }
    }
    // if the sign is negative, make the result negative
    if(str[0] == '-'){
      num *= -1;
    }

    fprintf(fout, "%.5f ", num);
    // add num to the array nums, add num to the sum, reset num and muti for the next string
    nums[k] = num;
    sum += num;
    k++;
    num = 0;
    muti = 1;
  }

  fprintf(fout, "\nSum is %f, Average is %f", sum, sum/k);
  fclose(fin);
  fclose(fout);
  return 0;
}
