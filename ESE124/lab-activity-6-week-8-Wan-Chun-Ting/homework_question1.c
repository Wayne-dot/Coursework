#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define limit 6
#define length 20

// letters are in the correct position
// letters are in the word but in the wrong position
// letters are not in the word

int main()
{
  char word[] = "sense"; //only in lowercase
  char answer[] = "-----";
  char input[length];
  char character;
  int trial = limit, inword = 0;

  while (trial > 0)
  {
    printf("Guess a word: ");
    scanf("%s", input); getchar();
    // iterate through each character for user input
    for(int i = 0 ; i < strlen(input) ; i++){
      for (int j = 0; j < strlen(word) ; j++){
        // if the character is inside the word
        if(input[i] == word[j]){
          inword = 1;
          if(i == j){
            // and same position
            answer[i] = input[i];
            break;
          }
          // if the character is in the word but not the same position
          else if( i != j && input[i] != word[i]){
            printf("%c is in the word but wrong position\n", input[i]);
            break;
          }
        }
      }
      
      // if the chracter is not in the word
      if(inword == 0){
        printf("%c is not in the word\n", input[i]);
      }

      inword = 0;

    }

    // check if user guess right
    if(strcmp(answer, word) == 0){
      printf("Congrats, You beat the game!");
      exit(0);
    }

    // present current answer status
    for(int i = 0 ; i < strlen(answer); i++){
      printf("%c", answer[i]);
    }
    printf("\n");

    trial --;
    inword = 0;
  }


  printf("You lost\n");

  return 0;
  
}


