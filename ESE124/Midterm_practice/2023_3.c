// Design a C program that reads words from an input file called “words.txt” 
// and creates the following output file called “output_words.txt”: each lower case letter in the input file is converted into an upper case letter on the output file, 
// and each upper case letter in the input file is converted into a lower case letter in the output file. The input file contains only words made from letters, spaces, and new lines.

#include <stdio.h>
#include <string.h>

#define MAX 30

int main(){
    FILE *fin1, *fin2;
    char words[MAX];
    char new;

    fin1 = fopen("Input_file.txt", "r");
    fin2 = fopen("Output_file.txt", "w");

    while((fscanf(fin1, "%s", words))!= EOF){
        for (int i = 0; i < strlen(words); i++)
        {
            if(words[i] >= 'a' && words[i] <= 'z'){
                words[i] -= 32;
            }
            else if(words[i] >= 'A' && words[i] <= 'Z'){
                words[i] += 32;
            }
            fprintf(fin2, "%c", words[i]);
        }
        fprintf(fin2, " ");
    }
    
    return 0;
}