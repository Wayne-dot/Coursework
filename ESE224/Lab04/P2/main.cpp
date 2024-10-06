
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

// 1 = Rock
// 2 = Paper
// 3 = Scissors

string num_to_action(int index){
    // converting from number to string action
    if(index == 1){
        return "Rock";
    }
    else if(index == 2){
        return "Paper";
    }
    else if (index == 3) {
        return "Scissors";
    }
    return "Error";
}

int determine_winner(int act1, int act2){
    // return if player 1 or player 2 win
    // if player 1 win, return 1, if player 2 win, return 2
    // if draw, return 0
    // return -1 for error

    if(act1 == act2){
        return 0;
    }

    if(act1 == 1){
        if(act2 == 2){
            return 2;
        }
        else if (act2 == 3) {
            return 1;
        }
    }
    else if (act1 == 2) {
        if(act2 == 1){
            return 1;
        }
        else if (act2 == 3) {
            return 2;
        }
    }
    else if (act1 == 3) {
        if(act2 == 1){
            return 2;
        }
        else if (act2 == 2) {
            return 1;
        }
    }

    return -1;
}

int main(){

    srand(time(0));

    Player player1("1"), player2("2");

    int action1, action2;

    for(int i = 0 ; i < 5 ; i++){
        cout << "Round " << i+1 << ":" << endl;
        action1 = player1.makeChoice();
        action2 = player2.makeChoice();

        int result = determine_winner(action1, action2);

        cout << "Player " << player1.getName() << " choose " << num_to_action(action1) << ", Player " << player2.getName() << " choose " << num_to_action(action2) << ". ";

        if(result == 1){
            player1.incrementWins();
            cout << "Player " << player1.getName() << " win!";
        }
        else if (result == 2) {
            player2.incrementWins();
            cout << "Player " << player2.getName() << " win!";
        }
        else if (result == 0) {
            cout << "It's a draw!";
        }
        cout << endl << endl;
    }

    cout << "Final Result:" << endl;
    cout << "Player 1: " << player1.getWins() << " wins" << endl;
    cout << "Player 2: " << player2.getWins() << " wins" << endl;

    if(player1.getWins() == player2.getWins()){
        cout << "The game is a draw!" << endl;
    }
    else if (player1.getWins() > player2.getWins()) {
        cout << "Player " << player1.getName() << " win overall!" << endl;
    }
    else if (player1.getWins() < player2.getWins()) {
        cout << "Player " << player1.getName() << " win overall!" << endl;
    }

    return 0;
}