#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "actions.h"
#include "memory.h"

int count = 0;
int score = 0;
int L_itch = 0;
int R_itch = 0;
int F_itch = 0;
int B_itch = 0;
int jump = 0;

void actions(char *str, FILE *faction, int *step_number_pointer, int row, int column, char maze[][MAXESIZE], int current_position[2], char list_of_perform_action[][1000]){
    // str = action in string
    // faction = file pointer
    // *step_number_pointer = number of step pointer
    // modify_maze = maze in integer, each number is repesetn by a symbol, explained in note.txt

    if(strcmp(str, "MARK") == 0){
        // put -3 for the pheremon
        maze[current_position[0]][current_position[1]] = '.';
        strcpy(list_of_perform_action[count], "Mark");
    }
    else if(strcmp(str, "MOVE_F") == 0){
        *step_number_pointer += 1;
        current_position[0] += 1;
        strcpy(list_of_perform_action[count], "MOVE_F");
    }
    else if(strcmp(str, "MOVE_B") == 0){
        *step_number_pointer += 1;
        current_position[0] -= 1;
        strcpy(list_of_perform_action[count], "MOVE_B");
    }
    else if(strcmp(str, "MOVE_L") == 0){
        *step_number_pointer += 1;
        current_position[1] -= 1;
        strcpy(list_of_perform_action[count], "MOVE_L");
    }
    else if(strcmp(str, "MOVE_R") == 0){
        *step_number_pointer += 1;
        current_position[1] += 1;
        strcpy(list_of_perform_action[count], "MOVE_R");
    }
    else if(strcmp(str, "CWL") == 0){
        strcpy(list_of_perform_action[count], "CWL");
        if ( maze[current_position[0]][current_position[1] - 1] == ' ')
        {
            printf("Left Itch !\n");
            L_itch = 1;
        }
        else
        {
            printf("no Left itch !\n");
            L_itch = 0;
        }
    }
    else if(strcmp(str, "CWR") == 0){
        strcpy(list_of_perform_action[count], "CWR");
        if (maze[current_position[0]][current_position[1] + 1] == ' ')
        {
            printf("Right Itch !\n");
            R_itch = 1;
        }
        else
        {
            printf("no Right itch !\n");
            R_itch = 0;
        }
    }
    else if(strcmp(str, "CWF") == 0){
        strcpy(list_of_perform_action[count], "CWF");
        if (maze[current_position[0] + 1][current_position[1]] == ' ')
        {
            printf("Forward Itch !\n");
            F_itch = 1;
        }
        else
        {
            printf("no Forward itch !\n");
            F_itch = 0;
        }
    }
    else if(strcmp(str, "CWB") == 0){
        strcpy(list_of_perform_action[count], "CWB");
        if (maze[current_position[0] - 1][current_position[1]] == ' ')
        {
            printf("Backward Itch !\n");
            B_itch = 1;
        }
        else
        {
            printf("no Backward itch !\n");
            B_itch = 0;
        }
    }
    else if(strcmp(str, "BJPI") == 0){
        strcpy(list_of_perform_action[count], "BJPI");
        while (L_itch == 1|| R_itch == 1|| F_itch == 1 || B_itch == 1) // if the ant feels and itch 
        {
            jump++; // x-jump is a counter so how many ever itch its enocunters it jumps
        }

        if (L_itch == 1)
        {
             current_position[1] += jump;
        }
        else if (R_itch == 1)
        {
             current_position[1] += jump;
        }
        else if (F_itch == 1)
        {
             current_position[0] += jump;
        }
        else if (B_itch == 1)
        {
             current_position[0] += jump;
        }
    }

    else if(strcmp(str, "CJPI") == 0){
        strcpy(list_of_perform_action[count], "CJPI");
        while (L_itch == 1 || R_itch == 1 || F_itch == 1 || B_itch == 1) // if the ant feels and itch 
        {
            jump++; // x-jump is a counter so how many ever itch its enocunters it jumps
            
        }

        if (L_itch == 1)
        {
             current_position[1] -= 1;
        }
        else if (R_itch == 1)
        {
             current_position[1] += 1;
        }
        else if (F_itch == 1)
        {
             current_position[0] += 1;
        }
        else if (B_itch == 1)
        {
             current_position[0] -= 1;
        }
    }
    else if(strcmp(str, "BACKTRACK") == 0){
        strcpy(list_of_perform_action[count], "BACKTRACK");

        int *result = peek();
        current_position[0] = result[0];
        current_position[1] = result[1];
    }
    else if(strcmp(str, "PUSH") == 0){
        strcpy(list_of_perform_action[count], "PUSH");
        push(current_position[0], current_position[1]);
    }
    else if(strcmp(str, "POP") == 0){
        strcpy(list_of_perform_action[count], "POP");
        pop();
    }
    else if(strcmp(str, "PEEK") == 0){
        strcpy(list_of_perform_action[count], "PEEK");
        int *result = peek();
    }
    else if(strcmp(str, "CLEAR") == 0){
        strcpy(list_of_perform_action[count], "CLEAR");
        clear();
    }
    if(maze[current_position[0]][current_position[1]] >= '0' && maze[current_position[0]][current_position[1]] <= '9'){
        score += maze[current_position[0]][current_position[1]] - '0';
    }
    

    // NOTE: R P 3 5 = for loop for the next three line 5 times
    // Check for R P action, since this is the only command that start with 'R'
    else if(str[0] == 'R'){
        // initlize variable
        int number_of_next_line = str[4] - '0', loop = str[6] - '0', number_of_action = 0;
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
                actions(list_of_next_action[j], faction, step_number_pointer, row, column, maze, current_position, list_of_perform_action);
            }
        }
        number_of_action = 0;
    }

    count += 1;
}

