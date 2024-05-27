
#include <stdio.h>
#include <string.h>

// Accepts strings with exactly 3 A's

// next state table
// A, default
// state0 {1, 4}
// state1 {2, 5}
// state2 {3, 6}
// state3 {7, 3}
// state4 {1, 4}
// state5 {2, 5}
// state6 {3, 6}
// state7 {7, 7}

// output table
// A, default
// state0 {0, 0}
// state1 {0, 0}
// state2 {1, 0}
// state3 {0, 1}
// state4 {0, 0}
// state5 {0, 0}
// state6 {0, 0}
// state7 {0, 0}

#define STATE0 0
#define STATE1 1
#define STATE2 2
#define STATE3 3
#define STATE4 4
#define STATE5 5
#define STATE6 6
#define STATE7 7

int main(){
    int output = 0, j = 0, select = 0;
    char chara;

    int next_state_table[8][2] = {
        {1, 4},
        {2, 5},
        {3, 6},
        {7, 3},
        {1, 4},
        {2, 5},
        {3, 6},
        {7, 7},
    };

    int output_table[8][2] = {
        {0, 0},
        {0, 0},
        {1, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
    };
    
    int current_state = STATE0;
    char *input_str = "gsdAsdfAsgsA";

    for(int i = 0 ; i < strlen(input_str) ; i++){
        chara = input_str[i];
        if(chara == 'A'){
            j = 0;
        }
        else{
            j = 1;
        }
        // update the state, then output
        current_state = next_state_table[current_state][j];
        output = output_table[current_state][j];
        // if the 3 A's is count
        if(output == 1){
            select = 1;
        }
    }

    // final check if the current state is at state 7, make sure there is no more than 3 A's
    if(select == 1 && current_state != STATE7){
        printf("Accepted string");
    }
    else{
        printf("String not accpeted");
    }


    
    return 0;
}
