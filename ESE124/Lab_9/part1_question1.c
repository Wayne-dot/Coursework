
#include <stdio.h>
#include <string.h>

#define STATE0 0
#define STATE1 1
#define STATE2 2
#define STATE3 3
#define STATE4 4

int main(){
    int i, j, output, sum = 0;
    char input;
    // setting the next state and output table
    int next_state_table[5][3] = {
        {1, 0, 0},
        {1, 2, 0},
        {3, 0, 0},
        {1, 4, 0},
        {3, 0, 0},
    };

    int output_table[5][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };

    int currentstate = STATE0;
    // testing string
    char *input_str = "FRFRFRFR";
    // intereated each character
    for(i = 0 ; i < strlen(input_str) ; i++){
        input = input_str[i];
        if(input == 'F'){
            j = 0;
        }
        else if(input == 'R'){
            j = 1;
        }
        else{
            j = 2;
        }
        // output, update state
        output = output_table[currentstate][j];
        currentstate = next_state_table[currentstate][j];
        // count number of FRFR
        if(output == 1){
            sum += 1;
        }
    }

    printf("Number of FRFR = %d ", sum);
    return 0;
}