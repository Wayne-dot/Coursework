// SBU ID: 115334926


#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main(){
	// initlize the variable
	int n;
	FILE *fin;
	fin = fopen("input.txt", "r");
	char word[MAX], c;
	int i;
	// exit if file not found
	if(fin == NULL){
		printf("File not found");
		exit(1);
	}
	// getting maximum number of guess
	printf("Maximum number of incorrect guesses: ");
	scanf("%d", &n);
	
	c = fgetc(fin);
	i = 0;
	// getting element into the array name word
	while(c != EOF){
		word[i] = c;
		i += 1;
		c = fgetc(fin);	
	}
	
	int counter = i;
	
	char guess[MAX];

	int a = 0;
	
	for(i = 0 ; i < n; i++){
		printf("Guess a word: ");
		scanf("%s", guess); getchar();
		// adding to a by 1 if each character is match
		for(int j = 0 ; j < counter; j++){
			if(word[j] == guess[j]){
				a += 1;
			}
		}
		// if all character match, exit with 0, user win
		if( a == counter){
			printf("This is the right guess\n");
			printf("You win, computer lost\n");
			exit(0);
		}
		else{
			printf("This is not the right guess\n");
		}
		a = 0;
	}
	// if all try used, user lose
	printf("You lost, computer win\n");
	
	return 0;
}
