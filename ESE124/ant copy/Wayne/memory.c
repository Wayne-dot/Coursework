#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"
#include "actions.h"

#define MAX_SIZE 1000

int row[MAX_SIZE], column[MAX_SIZE], top;

// x is the row number and y is the column number
// list of function need to be implement

// all function are initlize in void return type and empty input, feel free to change them

// added comment

void pop()
{
    printf("This is pop\n");
}

void push(int r)
{
    printf("This is push\n");

    // if (!full()) {
    //     row[MAX_SIZE] = r;
    //     top++;
    // }
    // else{
    //     printf("error: Memory is full\n");
    //     exit(1);
    // }

    //  if (!full()) {
    //     // column[MAX_SIZE] = c;
    //     top++;
    // }
    // else{
    //     printf("error: Memory is full\n");
    //     exit(1);
    // }
}

void clear()
{
    printf("This is clear");
    top = 0;
}

int empty()
{
    if (top == 0)
        return 1;
    else
    {
        return 0;
    }   
}

int full()
{
    if (top == MAX_SIZE)
        return 1;
    else
    {
        return 0;
    }
    
}
