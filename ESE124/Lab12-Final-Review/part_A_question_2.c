// Use a Finite State Machine (FSM) to solve the following problem: A sequence detector receives
// integers at its input, one integer at a time. The FSM outputs a 1 (integer) only if among the last
// three inputs exactly two were odd numbers. Otherwise, the FSM outputs a 0 (integer)

// even, odd
// f_digit, s_digitl, t_digit
// 0,    1,   2,   3,   4,   5,   6,   7
// EEE, EEO, EOE, EOO, OEE, OEO, OOE, OOO
// []

// even, odd
// fist []
// sec  []
// thir []

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    int next_state_table[8][2] = {
        {0, 1},
        {2, 3},
        {4, 5},
        {6, 7},
        {0, 1},
        {2, 3},
        {4, 5},
        {6, 7},
    };
    int output_tablep[8][2] = {
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
    };

    int input[] = {2, 4, 6, 7, 3, 6, 7, 9};
    int check[3];
    int even = 0, odd = 0;

    // get the current state
    int current_state;
    for(int i = 0 ; i < 3; i++){
        check[i] = input[i];
    }

    
    int j, outout;
    for(int i = 0 ; i < strlen(input) ; i++){
        if(input[i] % 2 == 0){
            j = 0;
        }
        else{
            j = 1;
        }
        current_state = current_state[current_state][j];
        output = output_tablep[current_state][j];
    }


    return 0;
}