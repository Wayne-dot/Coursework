#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50
#define LENGTH 100

void *ToPigLatin(char *word){
    char character;
    int i = 0, j = 0, cap = 0;
    // check if the first letter is volwel, uppercase or lowercase
    if(word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U' || word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u'){
        strcat(word, "way");
        return word;
    }

    if(word[0] >= 'A' && word[0] <= 'Z'){
        // convert first letter to lowercase, set cap to 1
        word[0] = word[0] - 'A' + 'a';
        cap = 1;
    }
    // y is treat normal in the firs letter, but vowel after
    if(word[0] == 'y'){
        character = word[0];
        for(j = 0 ; j < strlen(word) - 1; j++){
            word[j] = word[j+1];
        }
        word[j] = character;
    }

    // looping while the first character is a vowel
    while(word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u' && word[i] != 'y'){
        character = word[i];
        for(j = 0 ; j < strlen(word) - 1; j++){
            word[j] = word[j+1];
        }
        word[j] = character;
    }
    // set the first letter to capital if cap is set to 1
    if(cap == 1){
        word[0] = word[0] - 'a' + 'A';
    }
    strcat(word, "ay");
    // reset the cap
    cap = 0;
    return word;
}

int main(){
    char list[LENGTH], word[MAX];
    int i, j;

    printf("Input 5 words: ");
    scanf("%[^\n]", list);

    printf("\nPig Latin version of the 5 words:\n");
    i = 0, j = 0;
    for(i = 0 ; list[i] != '\0' ; i++){
        if(list[i] != ' '){
            word[j] = list[i];
            j++;
        }
        else{
            word[j] = '\0';
            // call the funciton for each word
            ToPigLatin(word);
            printf("%s ", word);
            j = 0;
        }
    }
    // last word
    if(j > 0){
        word[j] = '\0';
        ToPigLatin(word);
        printf("%s\n", word);
    }
    return 0;
}