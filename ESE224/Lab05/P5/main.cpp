
#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

char* Reverse_String(char str[], int size){
    char* reverse = new char[size + 1];

    for(int i = 0 ; i < size ; i++){
        // str[size] = '\0'
        reverse[i] = str[size - i - 1];
    }
    reverse[size] = '\0';
    return reverse;
}



int main(){

    char character_string[100];

    cout << "Enter a string: ";
    cin.getline(character_string, 100);

    cout << endl;

    int length = strlen(character_string);
    cout << "Length of the string " << length << endl;

    char* reverse_string = Reverse_String(character_string, length);
    cout << "Reverse string: " << reverse_string << endl;

    for(int i = 0 ; i < length ; i++){
        character_string[i] = toupper(character_string[i]);
    }
    cout << "Uppercase string: " << character_string << endl;

    int sum_vowel = 0;
    for(int i = 0 ; i < length ; i++){
        if(character_string[i] == 'A' || character_string[i] == 'E' || character_string[i] == 'I' || character_string[i] == 'O' || character_string[i] == 'U'){
            sum_vowel += 1;
        }
    }
    cout << "Number of vowels: " << sum_vowel << endl;


    return 0;
}