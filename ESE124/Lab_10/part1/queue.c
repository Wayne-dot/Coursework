#include <stdio.h>
#include "queue.h"

#define MAX_SIZE 1000

int row[MAX_SIZE], column[MAX_SIZE];
int end;

void top(int *r, int *c){
    *r = row[0];
    *c = column[0];
}

// reset stack by setting top to -1
void clear(){
    end = 0;
}

// 1 if the queue is empty, else 0
int is_empty(){
    if(end == 0){
        return 1;
    }
    else{
        return 0;
    }
}

// 1 if the queue is full 
int is_full(){
    return end >= MAX_SIZE;
}

// add new string at the end of the queue
void add(int a, int b){
    if(!is_full()){
        row[end] = a;
        column[end] = b;
        end++;
    }
    else{
        printf("Error: Queue is full\n");
    }
}

// remove string from the front of the queue
void remove_front(){
    if(!is_empty()){
        for(int i = 0 ; i < end ; i++){
            row[i] = row[i+1];
            column[i] = column[i+1];
        }
        end--;
    }
    else{
        printf("Queue is empty, nothing to remove\n");
    }
}

// print out the row and column queue for testing
void print_queue(){
    printf("Row: ");
    for(int i = 0 ; i < end; i++){
        printf("%d ", row[i]);
    }
    printf("\n");

    printf("Column: ");
    for(int i = 0 ; i < end; i++){
        printf("%d ", column[i]);
    }
    printf("\n");
}