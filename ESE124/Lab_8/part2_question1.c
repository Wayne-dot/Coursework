#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int my_strcmp(char ch1[], char ch2[]){

    int i;
    for(i = 0 ; ch1[i] != '\0' && ch2[i] != '\0' ; i++){
        if(ch1[i] != ch2[i]){
            return 1;
        }
    }
    if(ch1[i] != ch2[i]){
        return 1;
    }
    return 0;
}

int my_strncmp(int n, char ch1[], char ch2[]){
    int i;

    for(i = 0 ; i < n && ch1[i] != '\0' && ch2[i] != '\0'; i++){
        if(ch1[i] != ch2[i]){
            return 1;
        }
    }
    if(ch1[i] != ch2[i]){
        return 1;
    }
    return 0;
}

char *my_strcpy(char* ch1, char ch2[]){
    int i;

    for(i = 0 ; ch1[i] != '\0' && ch2[i] != '\0' ; i++){
        ch1[i] = ch2[i];
    }
    ch1[i] = '\0';
    return ch1;
}

char *my_strcat(char *ch1, char * ch2){
    int i, j;
    for(i = 0 ; ch1[i] != '\0';i++){
    }

    for(j = 0; ch2[j] != '\0' ; j++){
        ch1[i] = ch2[j];
        i++;
    }
    ch1[i] = '\0';
    return ch1;
}

char *my_reverse(char *ch1, char *ch2){
    int i = 0, j, k;
    for(j = 0 ; ch2[j] != '\0'; j++){}

    for(k = j - 1; k >= 0; k--, i++){
        ch1[i] = ch2[k];
    }
    ch1[i] = '\0';
    return ch1;
}

int main(){
    char str1[MAX] = "abcde";
    char str2[MAX] = "abcde";
    printf("Result of compare string between %s and %s is %d\n", str1, str2, my_strcmp(str1, str2));

    char str3[MAX] = "abc";
    printf("Result of compare string between %s and %s is %d\n", str1, str3, my_strcmp(str1, str3));

    int n = 4;
    printf("Result of compare string between %s and %s of the first %d character is %d\n", str1, str2, n, my_strncmp(n, str1, str2));

    n = 2;
    printf("Result of compare string between %s and %s of the first %d character is %d\n", str1, str3, n, my_strncmp(n, str1, str3));

    char first[MAX] = "234";
    char second[MAX] = "hwe";

    printf("Result of copying from the second string to the first string is %s\n", my_strcpy(first, second));

    char third[MAX] = "what";
    printf("Result of copying from the second string to the third string is %s\n", my_strcpy(third, second));

    char test1[MAX] = "compu";
    char test2[MAX] = "ter";
    printf("Result of append second string to end of first string is %s\n", my_strcat(test1, test2));

    char test3[MAX] = "Mon";
    char test4[MAX] = "day";
    printf("Result of append second string to end of first string is %s\n", my_strcat(test3, test4));

    char rever1[MAX] = "abcdef";
    char rever2[MAX] = "terminal";
    printf("Result of reverse second string to the first string is %s\n", my_reverse(rever1, rever2));

    char rever3[MAX] = "abc";
    char rever4[MAX] = "input string";
    printf("Result of reverse second string to the first string is %s\n", my_reverse(rever3, rever4));

    return 0;
}