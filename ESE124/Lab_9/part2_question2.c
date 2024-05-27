

#include <stdio.h>
#include <string.h>

// Accepts any string containing MURMURS

// next state table
// M U R S default
// state 0 {1, 0, 0, 0, 0}
// state 1 {1, 2, 0, 0, 0}
// state 2 {1, 0, 3, 0, 0}
// state 3 {4, 0, 0, 0, 0}
// state 4 {1, 5, 0, 0, 0}
// state 5 {1, 0, 6, 0, 0}
// state 6 {4, 0, 0, 0, 0}

// output table
// M U R S defauly
// state 0 {0, 0, 0, 0, 0}
// state 1 {0, 0, 0, 0, 0}
// state 2 {0, 0, 0, 0, 0}
// state 3 {0, 0, 0, 0, 0}
// state 4 {0, 0, 0, 0, 0}
// state 5 {0, 0, 0, 0, 0}
// state 6 {0, 0, 0, 1, 0}


#define STATE0 0
#define STATE1 1
#define STATE2 2
#define STATE3 3
#define STATE4 4
#define STATE5 5
#define STATE6 6

int main(){
    char chara;
    int output, j = 0, sum = 0;

    int next_state_table[7][5] = {
        {1, 0, 0, 0, 0},
        {1, 2, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {4, 0, 0, 0, 0},
        {1, 5, 0, 0, 0},
        {1, 0, 6, 0, 0},
        {4, 0, 0, 0, 0},
    };

    int output_table[7][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
    };

    int current_state = STATE0;

    char *input_str = "MURMURMURSMURMURS";

    for(int i = 0 ; i < strlen(input_str) ; i++){
        chara = input_str[i];
        if(chara == 'M'){
            j = 0;
        }
        else if(chara == 'U'){
            j = 1;
        }
        else if(chara == 'R'){
            j = 2;
        }
        else if(chara == 'S'){
            j = 3;
        }
        else{
            j = 4;
        }

        output = output_table[current_state][j];
        current_state = next_state_table[current_state][j];

        if(output == 1){
            sum += 1;
        }
    }

    printf("Number of MURMURS = %d", sum);

    return 0;
}