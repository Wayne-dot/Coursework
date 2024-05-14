#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int main()
{
  FILE *fin, *fout;
  char str[MAX], c;
  int pos[2] = {0, 0};
  int i = 0, x, iden = 0; //0 = init, 1 = left, 2 = right, 3 = up, 4 = right
  fin = fopen("input.txt", "r");
  fout = fopen("output.txt", "w");

  if(fin == NULL || fout == NULL){
    printf("Files not found");
    exit(1);
  }

  while((fscanf(fin, "%s", str)) != EOF){
    // adjust the position according to the identifier
    if(str[0] >= '0' && str[0] <= '9'){
      x = str[0] - '0';
      if(iden == 0){
        pos[i] = x;
        i++;
      }
      else if(iden == 1){
        pos[0] -= x;
      }
      else if(iden == 2){
        pos[0] += x;
      }
      else if(iden == 3){
        pos[1] += x;
      }
      else if(iden == 4){
        pos[1] -= x;
      }
      
    }
    else{
      // adjust the iden according to the string
      if(strcmp(str, "INITIAL") == 0){
        iden = 0;
      }
      else if(strcmp(str, "UP") == 0){
        iden = 3;
      }
      else if(strcmp(str, "DOWN") == 0){
        iden = 4;
      }
      else if(strcmp(str, "LEFT") == 0){
        iden = 1;
      }
      else if(strcmp(str, "RIGHT") == 0){
        iden = 2;
      }
      // printout the position vector
      if(iden != 0){
        fprintf(fout, "Position: ");
        for(int j = 0; j < 2 ; j++){
          fprintf(fout, "%d ", pos[j]);
        }
        fprintf(fout, "\n");
      }

      i = 0;
    }
  }
  // print out the last position vector
  fprintf(fout, "Position: ");
  for(int j = 0; j < 2 ; j++){
    fprintf(fout, "%d ", pos[j]);
  }



  fclose(fin);
  fclose(fout);
  return 0;
}
