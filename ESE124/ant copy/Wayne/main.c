#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "memory.h"
#include "actions.h"

#define MAXESIZE 100
#define MAX_ACTIONS 100

int main(){
    int row = 0, column = 0, MAX_NUMBER_OF_STEPS = 100, number_of_step = 0;
    int modify_maze[MAXESIZE][MAXESIZE], current_position[2] = {3, 4};
    char c;
    char action[MAX_ACTIONS], maze[MAXESIZE][MAXESIZE], list_of_perform_action[1000][1000];

    FILE *fin, *faction, *fout;
    fin = fopen("maze.txt", "r");
    faction = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    if(fin == NULL){
        printf("File maze.txt can not be found\n");
        exit(1);
    }

    if(faction == NULL){
        printf("File input.txt can not be found\n");
        exit(1);
    }

    if(fout == NULL){
        printf("File output.txt can not be found\n");
        exit(1);
    }

    // reading the maze from the maze.txt file  
    while((c = fgetc(fin)) != EOF){
        if(c == '\n'){
            row += 1;
            column = 0;
        }
        else{
            maze[row][column] = c;
            column += 1;
        }
    }

    // // -1 = *, -2 = space
    // for(int i = 0 ; i <= row; i ++){
    //     for(int j = 0 ; j <= column ; j++){
    //         if(maze[i][j] == '*'){
    //             modify_maze[i][j] = -1;
    //         }
    //         else if(maze[i][j] == ' '){
    //             modify_maze[i][j] = -2;
    //         }
    //         else if(maze[i][j] >= '0' && maze[i][j] <= '9'){
    //             modify_maze[i][j] = maze[i][j] - '0';
    //         }
    //     }
    // }

    // initlize pointer of the number of step
    int *step_number_pointer = &number_of_step;

    // read each action from action.txt
    while (fgets(action, MAX_ACTIONS, faction) != NULL)
    {
        // set the temrined character
        action[strlen(action)-1] = '\0';

        actions(action, faction, step_number_pointer, row, column, maze, current_position, list_of_perform_action);

        // check if number of step is less than maximum nnumber of step
        if(number_of_step > MAX_NUMBER_OF_STEPS){
            // stop the action
            printf("Number of step has reach maximum, exit program\n");
            break;
        }
    }

    // print the performed action to the output file
    for(int i = 0 ; i < count ; i++){
        fprintf(fout, "%s\n", list_of_perform_action[i]);
    }


    // Display the progress
    for(int i = 0 ; i <= row; i ++){
        for(int j = 0 ; j <= column ; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // Display the progress
    for(int i = 0 ; i <= row; i ++){
        for(int j = 0 ; j < column ; j++){
            printf("%d", modify_maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    fclose(fin);
    fclose(faction);

    return 0;
}