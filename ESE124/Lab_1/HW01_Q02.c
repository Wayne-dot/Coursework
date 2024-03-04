//Wayne Ting SBU ID: 115334926

#include <stdio.h>
#include <ctype.h>

//Devise the following C program: Checks whether a character entered by the user from the keyboard is a vowel or a consonant. Then, displays the ASCII value of the character.

// In this program, a character is a vowel when the character is a, e, i, o, u

int main(){
//	initlize input leter
	char letter;
	
//	get the input
	printf("Enter a character: ");
	scanf("%c", &letter);
	printf("\n");
	
//	check if the letter is a vowel by converting to lowercase incase the user enter a upper case
	if (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' || tolower(letter) == 'o' || tolower(letter) == 'u'){
		printf("This charcter %c is vowel\n", letter);
	}
	else{
		printf("This charcter %c is consonant\n", letter);	
	}
	
//	display the ASCII value of the character with %d
	printf("The ASCII value of %c is %d", letter, letter);
	
	return 0;
}
