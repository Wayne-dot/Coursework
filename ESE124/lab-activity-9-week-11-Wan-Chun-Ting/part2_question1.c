// Wayne Ting SBU ID:115334926
#include <stdio.h>
#include <string.h>

#define STATE0 0
#define STATE1 1
#define STATE2 2
#define STATE3 3

// next state table
// F, R, O, G, default
// state 0 {1, 0, 0, 0, 0}
// state 1 {1, 2, 0, 0, 0}
// state 2 {1, 0, 3, 0, 0}
// state 3 {1, 0, 0, 0, 0}

// output table
// state 0 {0, 0, 0, 0, 0}
// state 1 {0, 0, 0, 0, 0}
// state 2 {0, 0, 0, 0, 0}
// state 3 {0, 0, 0, 1, 0}

int main(){
    int output, j, sum = 0;

    int next_state_table[4][5] = {
        {1, 0, 0, 0, 0},
        {1, 2, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {1, 0, 0, 0, 0},
    };

    int output_table[4][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
    };

    int currentstate = STATE0;
    // testing string
    char *input_str = "FROGREFROGFROGOFROFROG";

    for(int i = 0 ; i < strlen(input_str) ; i++){
        if(input_str[i] == 'F'){
            j = 0;
        }
        else if(input_str[i] == 'R'){
            j = 1;
        }
        else if(input_str[i] == 'O'){
            j = 2;
        }
        else if(input_str[i] == 'G'){
            j = 3;
        }
        output = output_table[currentstate][j];
        currentstate = next_state_table[currentstate][j];
        // count number of FROG
        if(output == 1){
            sum += 1;
        }
    }

    printf("NUmber of FROG = %d\n", sum);

    return 0;
}