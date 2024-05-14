#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tic tac toe

int main()
{
  char chart[3][3], chara = 'X', comp[3];
  int x, y, c = 0, finish = 0, draw = 1;
  // initlize array value
  for(int i = 0 ; i < 3 ; i++){
    for(int j = 0 ; j < 3; j++){
      chart[i][j] = '-';
    }
  }

  while(!finish){
    // showing which player turn
    if(c == 0){
      printf("Player 1 turn\n");
      chara = 'X';
      c = 1;
    }
    else{
      printf("Player 2 turn\n");
      chara = 'O';
      c = 0;
    }

    printf("List position you want to place in, either 1, 2 or 3, count from top to bottom, left to right\n");
    printf("row = ");
    scanf("%d", &x);
    printf("column = ");
    scanf("%d", &y);
    
    printf("\n");

    // check if the sport is empty, only put the value if the spot is empty
    if(chart[x-1][y-1] == '-'){
      chart[x-1][y-1] = chara;
    }
    // print out the current state tictactoe
    for(int i = 0 ; i < 3 ; i++){
      for(int j = 0 ; j < 3; j++){
        printf("%c", chart[i][j]);
      }
      printf("\n");
    }

    // check horizontal
    for(int i = 0 ; i < 3 ; i++){
      for(int j = 0 ; j < 3 ; j++){
        comp[j] = chart[i][j];
      }
      if(comp[0] == comp[1] && comp[1] == comp[2] && comp[0] != '-' && comp[1] != '-' && comp[2] != '-'){
        finish = 1;
      }
    }

    // check vertical
    for(int i = 0; i < 3; i++){
      for(int j = 0 ; j < 3; j++){
        comp[j] = chart[j][i];
      }
      if(comp[0] == comp[1] && comp[1] == comp[2] && comp[0] != '-' && comp[1] != '-' && comp[2] != '-'){
        finish = 1;
      }
    }

    // check diagonal
    for(int i = 0 ; i < 3 ; i++){
      comp[i] = chart[i][i];
    }
    if(comp[0] == comp[1] && comp[1] == comp[2] && comp[0] != '-' && comp[1] != '-' && comp[2] != '-'){
        finish = 1;
    }
    // check if the game is drawn
    for(int i = 0; i < 3 ; i++){
      for(int j = 0 ; j < 3; j++){
        if(chart[i][j] == '-'){
          draw = 0;
        }
      }
    }

    if(draw == 1){
      printf("Draw\n");
      exit(0);
    }

    printf("\n");
    draw = 1;
  }
  if(comp[0] == 'X'){
    printf("Player 1 win!\n");
  }
  else if(comp[0] == 'O'){
    printf("Player 2 win!\n");
  }
}
