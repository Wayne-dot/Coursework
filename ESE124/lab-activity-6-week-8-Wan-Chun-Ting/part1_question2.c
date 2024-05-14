// Extend the previous C program to include decimal numbers that also have a positive or 
// negative exponent. Both lower case ‘e’ and capital ‘E’ are accepted.

// Examples: 45.04e2; 5.67e-2; 34.5E3; 90.3E-09. 

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50


int main()
{
  FILE *fin, *fout;
  char str[MAX];
  float nums[MAX];
  int decimal_place, e = 0, expo = 0, up = 1, count = 0;
  float num = 0.0, muti = 1.0, x = 1.0, sum = 0.0;

  fin = fopen("input.txt", "r");
  fout = fopen("output.txt", "w");
  

  if(fin == NULL || fout == NULL){
    printf("File not found");
    exit(1);
  }

  fprintf(fout, "Values are: ");
  
  while((fscanf(fin, "%s", str)) != EOF){

    for(int i = 0; i < strlen(str); i++){
      if(str[i] == '.'){
        decimal_place = i;
        break;
      }
    }

    if(str[0] == '-' || str[0] == '+'){
      decimal_place -= 1;
    }

    // getting the maximum mutiplier
    for(int i = 1; i <= decimal_place - 1; i++){
      muti *= 10;
    }

    for(int i = 0 ; i < strlen(str) - 1; i++){
      // if the character is e / E, set e = 1, muti = 1
      if(str[i] == 'e' || str[i] == 'E'){
        e = 1;
        muti = 1.0;
      }
      // treat number at the expo as normal number
      if(e != 1){
        if(str[i] >= '0' && str[i] <= '9'){
          x = str[i] - '0';
          num += x * muti;
          muti *= 0.1;
        }
      }
      
      if(e == 1){
        if(str[i] == '-'){
          up = 0;
        }
        if(str[i] >= '0' && str[i] <= '9'){
          x = str[i] - '0';
          expo += x;
          muti *= 10;
        }
      }
    }
    // mutiply / divid by 10 by expo times
    for(int i = 0; i < expo; i++){
      if(up == 1){
        num *= 10;
      }
      else{
        num /= 10;
      }
    }

    if(str[0] == '-'){
      num *= -1;
    }

    fprintf(fout, "%.15f ", num);
    // add num to sum, reset num, muti, e, expo, up for the next string
    sum += num;
    num = 0.0;
    muti = 1;
    e = 0;
    expo = 0;
    up = 1;
    count += 1;
  }

  // output the value
  fprintf(fout, "\nSum is %.15f, average is %.15f", sum, sum/count);
  fclose(fin);
  fclose(fout);
  return 0;
}

