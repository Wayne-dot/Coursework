#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"
#include "actions.h"

#define MAX_SIZE 1000

int row[MAX_SIZE], column[MAX_SIZE], top;

// x is the column number and y is the row number
// list of function need to be implement

// all function are initlize in void return type and empty input, feel free to change them

// added comment



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

int* peek(){
    int* result = (int*) malloc(2 * sizeof(int));

    result[0] = row[top];
    result[1] = column[top];
    return result;
}

void pop()
{
    if (!empty())
        top--;
    else {
        printf("Memory is empty\n");
        exit (1);
    }
}

void push(int x, int y)
{

    if (!full()) {
        row[MAX_SIZE] = x; // x is the row but if intialized as another name change there
        top++;
    }
    else{
        printf("error: Memory is full\n");
        exit(1);
    }

     if (!full()) {
        column[MAX_SIZE] = y;  // y is the colomun but if intialized as another name change there
        top++;
    }
    else{
        printf("error: Memory is full\n");
        exit(1);
    }
}