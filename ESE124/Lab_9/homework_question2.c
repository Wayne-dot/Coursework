
#include <stdio.h>
#include <string.h>

// Accepts CYBOT followed by any characters

// next state table
// C, Y, B, O, T, default
// state0 {1, 6, 6, 6, 6, 6}
// state1 {6, 2, 6, 6, 6, 6}
// state2 {6, 6, 3, 6, 6, 6}
// state3 {6, 6, 6, 4, 6, 6}
// state4 {6, 6, 6, 6, 5, 6}
// state5 {5, 5, 5, 5, 5, 5}
// state6 {6, 6, 6, 6, 6, 6}

// output table
// state0 {0, 0, 0, 0, 0, 0}
// state1 {0, 0, 0, 0, 0, 0}
// state2 {0, 0, 0, 0, 0, 0}
// state3 {0, 0, 0, 0, 0, 0}
// state4 {0, 0, 0, 0, 1, 0}
// state5 {1, 1, 1, 1, 1, 1}
// state6 {0, 0, 0, 0, 0, 0}

#define STATE0 0
#define STATE1 1
#define STATE2 2
#define STATE3 3
#define STATE4 4
#define STATE5 5
#define STATE6 6

int main(){
    char chara;
    int output = 0, j = 0;
    
    int next_state_table[7][6] = {
        {1, 6, 6, 6, 6, 6},
        {6, 2, 6, 6, 6, 6},
        {6, 6, 3, 6, 6, 6},
        {6, 6, 6, 4, 6, 6},
        {6, 6, 6, 6, 5, 6},
        {5, 5, 5, 5, 5, 5},
        {6, 6, 6, 6, 6, 6},
    };

    int output_table[7][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0},
    };

    char *input_str = "CYBOTsgesg";
    int current_state = STATE0;

    for(int i = 0 ; i < strlen(input_str) ; i++){
        chara = input_str[i];
        if(chara == 'C'){
            j = 0;
        }
        else if(chara == 'Y'){
            j = 1;
        }
        else if(chara == 'B'){
            j = 2;
        }
        else if(chara == 'O'){
            j = 3;
        }
        else if(chara == 'T'){
            j = 4;
        }
        else{
            j = 5;
        }
        current_state = next_state_table[current_state][j];
        output = output_table[current_state][j];
    }
    // accepted if the string start with CYBOT
    if(output == 1){
        printf("Accepted string");
    }
    else{
        printf("String not accepted");
    }

    return 0;
}

