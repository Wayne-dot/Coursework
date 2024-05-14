#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "actions.h"
#include "memory.h"

int L_itch = 0;
int R_itch = 0;
int F_itch = 0;
int B_itch = 0;
int jump = 0; //BJPI jumping distance
void actions(char *str, FILE *faction, int *step_number_pointer, int row, int column, int modify_maze[][MAXESIZE], int current_position[2]){
    // str = action in string
    // faction = file pointer
    // *step_number_pointer = number of step pointer
    // modify_maze = maze in integer, each number is repesetn by a symbol, explained in note.txt

    if(strcmp(str, "MARK") == 0){
        // put -3 for the pheremon
        modify_maze[current_position[0]][current_position[1]] = -3;
    }
    else if(strcmp(str, "MOVE_F") == 0){
        *step_number_pointer += 1;
        printf("Move f\n");
        current_position[0] += 1;
        // column = column + 1;
        
    }
    else if(strcmp(str, "MOVE_B") == 0){
         *step_number_pointer += 1;
        printf("Move B\n");
         current_position[0] -= 1;
    }
    else if(strcmp(str, "MOVE_L") == 0){
        *step_number_pointer += 1;
        printf("Move L\n");
         current_position[1] -= 1;
       // row = row - 1; 
    }
    else if(strcmp(str, "MOVE_R") == 0){
         *step_number_pointer += 1;
        printf("Move R\n");
         current_position[1] += 1;
        //row = row + 1; 
    }
    else if(strcmp(str, "CWL") == 0){
        if ( current_position[1] - 1 = '-2')
        {
            printf("Left Itch !")
            L_itch = 1;
        }
        else
        {
            printf("no Left itch !")
            L_itch = 0;
        }
    }
    else if(strcmp(str, "CWR") == 0){
         if (current_position[1] + 1 = '-2')
        {
            printf("Right Itch !")
            R_itch = 1;
        }
        else
        {
            printf("no Right itch !")
            R_itch = 0;
        }
    }
    else if(strcmp(str, "CWF") == 0){
         if (current_position[0] + 1 = '-2')
        {
            printf("Forward Itch !")
            F_itch = 1;
        }
        else
        {
            printf("no Forward itch !")
            F_itch = 0;
        }
    }
    else if(strcmp(str, "CWB") == 0){
         if (current_position[0] - 1 = '-2')
        {
            printf("Backward Itch !")
            B_itch = 1;
        }
        else
        {
            printf("no Backward itch !")
            B_itch = 0;
        }
    }
    else if(strcmp(str, "BJPI") == 0){
        while (L_itch || R_itch || F_itch || B_itch = 1) // if the ant feels and itch 
        {
            jump++; // x-jump is a counter so how many ever itch its enocunters it jumps
            
        }

        if (L_itch = 1)
        {
             current_position[1] -= jump;
        }
        else if (R_itch = 1)
        {
             current_position[1] += jump;
        }
        else if (F_itch = 1)
        {
             current_position[0] += jump;
        }
        else if (B_itch = 1)
        {
             current_position[0] -= jump;
        }
       
        
    }

    else if(strcmp(str, "CJPI") == 0){
         while (L_itch || R_itch || F_itch || B_itch = 1) // if the ant feels and itch 
        {
            jump++; // x-jump is a counter so how many ever itch its enocunters it jumps
            
        }

        if (L_itch = 1)
        {
             current_position[1] -= 1;
        }
        else if (R_itch = 1)
        {
             current_position[1] += 1;
        }
        else if (F_itch = 1)
        {
             current_position[0] += 1;
        }
        else if (B_itch = 1)
        {
             current_position[0] -= 1;
        }
    }
    else if(strcmp(str, "BACKTRACK") == 0){
        current_position[0] = column(top);
        current_position[1] = row(top);
    }
   

    // NOTE: R P 3 5 = for loop for the next three line 5 times
    // Check for R P action, since this is the only command that start with 'R'
    else if(str[0] == 'R'){
        // initlize variable
        int number_of_next_line = str[4] - '0', loop = str[6] - '0', number_of_action = 0, temp_maze[MAXESIZE][MAXESIZE], temp_position[2];
        char next_action[20], list_of_next_action[100][100];

        for(int i = 0 ; i < number_of_next_line ; i++){
            // get the action
            fscanf(faction, "%s", next_action);
            // set the terminal character
            next_action[strlen(next_action)] = '\0';
            // record to the list of next action
            strcpy(list_of_next_action[number_of_action], next_action);
            number_of_action += 1;
        }

        // iterated by loop times, perform the action
        for(int i = 0 ; i < loop ; i++){
            for(int j = 0 ; j < number_of_action ; j++){
                printf("%s", list_of_next_action[j]);
                actions(list_of_next_action[j], faction, step_number_pointer, temp_maze, temp_position);
            }
        }
        number_of_action = 0;
    }
}

