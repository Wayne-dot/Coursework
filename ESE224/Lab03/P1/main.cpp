
#include <cmath>
#include <fstream>
#include <iostream>
#include <ostream>
using namespace std;


int main(){
    ifstream inputFile("words.txt");

    if(!inputFile){
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string word, longest = "";

    int wordCount = 0, char_count = 0;

    while (inputFile >> word) {
        wordCount++;
        char_count += word.length();
        if(word.length() > longest.length()){
            longest = word;
        }
    }

    cout << "Total number of words: " << wordCount << endl;
    cout << "Total number of characters: " << char_count << endl;
    cout << "Longest word: " << longest << endl;

    inputFile.close();

    return 0;
}