#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main(){
    int row = 0, col = 0, shortpath[10][10], start[2], end[2], a, b;
    char c, maze[10][10];

    // initlize all element to -1
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            shortpath[i][j] = -1;
        }
    }

    FILE *fin;
    fin = fopen("maze.txt", "r");

    if(fin == NULL){
        printf("Files maze.txt not found");
        exit(1);
    }
    // getting data from the maze
    while((c=fgetc(fin)) != EOF){
        printf("%c", c);
        if(c != '\n'){
            maze[row][col] = c;
            col++;
        }
        else{
            col = 0;
            row++;
        }
    }

    printf("Input starting position:\n");
    printf("Starting row position: ");
    scanf("%d", &start[0]);
    printf("Starting column position: ");
    scanf("%d", &start[1]);

    printf("Input ending position:\n");
    printf("Starting row position: ");
    scanf("%d", &end[0]);
    printf("Starting column position: ");
    scanf("%d", &end[1]);

    // set the starting point to 0
    shortpath[start[0]][start[1]] = 0;
    // set the ending point to -2
    shortpath[end[0]][end[1]] = -2;

    // initlize the queue
    clear();
    // add the starting point
    add(start[0], start[1]);
    print_queue();

    // initilze toprow and topcolumn variable as int, put the the pointer to the agurment of top
    int top_row, top_col;
    top(&top_row, &top_col);

    // each each direction, left, right, down, top
    int direction[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int row_add, col_add;
    
    while (!is_empty())
    {
        // update the first element of row and column array
        top(&top_row, &top_col);
        // check if the top row, col is the destination
        if(top_row == end[0] && top_col == end[1]){
            printf("Destination reach\n");
            exit(0);
        }
        
        for(int i = 0 ; i < 4; i ++){
            row_add = direction[i][0];
            col_add = direction[i][1];

            // add to the queue if valid
            // check if the position is avaliable (empty), or if is previous spot
            printf("character is %c\n", maze[top_row+row_add][top_col+col_add]);
            if(maze[top_row+row_add][top_col+col_add] != '*' && shortpath[top_row+row_add][top_col+col_add] != 1 && shortpath[top_row+row_add][top_col+col_add] != 0){
                // put into the queue
                add(top_row+row_add, top_col+col_add);
                // update the shortpath
                shortpath[top_row+row_add][top_col+col_add] = 1;
            }
        }
        remove_front();
        print_queue();
        

        printf("\n");
        for(int i = 0 ; i < 10 ; i++){
            for(int j = 0 ; j < 10 ; j++){
                printf("%d ", shortpath[i][j]);
            }
            printf("\n");
        }
        printf("----------------\n");
    }

    printf("Destination not reach, no solution\n");
    return 0;
}