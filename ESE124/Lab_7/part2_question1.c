#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fin, *fout;
    char c;
    char text[11][330], str[330], oper, Rstring[11][330];
    int row = 1, col = 0, m, n;

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    if(fin == NULL || fout == NULL){
        printf("Files not found");
    }
    // getting data from the input file
    // \0 character is used to indicated end of line for the row, use for strlen()
    while((c = fgetc(fin)) != EOF){
      if(c == '\n'){
        text[row][col] = '\0';
        row++;
        col = 0;
      }
      if(c != '\n'){
        text[row][col] = c;
        col++;
      }
    }
    text[row][col] = '\0';

    // testing current state result
    for(int i = 1; i <= row; i++){
      for(int j = 0 ; j < strlen(text[i]) ; j++){
        printf("%c", text[i][j]);
      }
      printf("\n");
    }
    printf("\n");

    while (1)
    {
      printf("Operation: ");
      scanf("%c", &oper); getchar();

      if(oper == 'l'){
        printf("m: ");
        scanf("%d", &m); getchar();
        printf("Text: ");
        fgets(str, sizeof(str), stdin);
        // move the line down, when one line is assert 
        for(int i = row; i > m ; i--){
          for(int j = 0 ; j < strlen(text[i]) ; j++){
            text[i+1][j] = text[i][j];
          }
          text[i+1][strlen(text[i])] = '\0';
        }
        // put the extra line that is made, put the new string into that row
        for(int j = 0 ; j < strlen(str) ; j++){
          text[m+1][j] = str[j];
        }
        text[m+1][strlen(str)] = '\0';
        row++;
      }

      else if(oper == 'D'){
        printf("m: ");
        scanf("%d", &m); getchar();
        printf("n: ");
        scanf("%d", &n); getchar();
        // delte those line by swap with the bottom line
        for(int i = m, j = n + 1; j <= row; i++, j++){
          for(int k = 0 ; k <= strlen(text[j]) ; k++){
            text[i][k] = text[j][k];
          }
        }
        // decrease the row number according to user input
        row -= n - m + 1;
      }
      else if(oper == 'R'){
        printf("m: ");
        scanf("%d", &m); getchar();
        printf("n: ");
        scanf("%d", &n); getchar();

        for(int i = m; i <= n ; i++){
          printf("Newline %d: ", i);
          fgets(Rstring[i], sizeof(Rstring[i]), stdin);
          // replace each letter base on the user input
          for(int j = 0 ; j < strlen(text[i]); j++){
            text[i][j] = Rstring[i][j];
          }
        }
      }


      if(oper == 'E'){
        break;
      }

      // testing the result out
      for(int i = 1; i <= row; i++){
        for(int j = 0 ; j < strlen(text[i]) ; j++){
          printf("%c", text[i][j]);
        }
        printf("\n");
      }
    }

    // output the file to output txt, does not work inside the while loop
    for(int i = 1; i <= row; i++){
        for(int j = 0 ; j < strlen(text[i]) ; j++){
          c = text[i][j];
          fputc(c, fout);
        }
        fputc('\n', fout);
    }
    return 0;
}