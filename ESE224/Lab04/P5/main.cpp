
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main(){

    srand(time(0));
    int num = (rand() % 100) + 1;
    int attemps, guess;
    bool guess_right = false;

    ofstream OutputFile("guess_results.txt");
    

    cout << "Welcome to the Guess the Number Game!" << endl;
    cout << "I have picked a number between 1 and 100. Try to guess it!" << endl;


    while (!guess_right) {
        cout << "Enter your guess: ";
        cin >> guess;
        attemps += 1;
        if(guess > num){
            cout << "Too high!" << endl;
        }
        else if (guess < num) {
            cout << "Too low!" << endl;
        }
        else if(guess == num){
            cout << "Correct! You guess in " << attemps << " attemps." << endl;
            guess_right = true;
        }
    }

    OutputFile << "You guess the number in " << attemps << " attemps." << endl;

    return 0;
}