
#include "Player.h"
#include <cstdlib>

// 1 = Rock
// 2 = Paper
// 3 = Scissors

Player::Player() : name("Name"), wins(0){}

Player::Player(string n_name): name(n_name), wins(0){

}

int Player::makeChoice(){
    int randomChoice = (rand() % 3) + 1;
    return randomChoice;
}

void Player::incrementWins(){
    wins += 1;
}

int Player::getWins(){
    return wins;
}

string Player::getName(){
    return name;
}