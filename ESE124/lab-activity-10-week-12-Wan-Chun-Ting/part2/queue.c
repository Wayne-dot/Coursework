#include <stdio.h>
#include "queue.h"

#define MAX_SIZE 1000

int cir_queue[MAX_SIZE];
int front = -1, end = -1, size;

int first(){
    return cir_queue[front];
}

int one_left(){
    return front == end;
}

int is_empty(){
    return (front == -1) && (end == -1);
}

int is_full(){
    return (end + 1) % size == front;
}

void init(int max_size){
    size = max_size;
    int a = 0;
    // setting array from 1 to max size
    for(int i = 0 ; i < size ; i++){
        cir_queue[i] = i+1;
    }
    front = 0;
    end = size - 1;
}

void add(int element){
    if(!is_full()){
        end = (end + 1)%size;
        cir_queue[end] = element;
    }
    else{
        printf("Queue is full\n");
    }
}

void pop(){
    if(!is_empty()){
        cir_queue[front] = 0;
        front = (front + 1)%size;
    }
    else{
        printf("Queue is empty\n");
    }
}

void print_queue(){
    for(int i = front ; i != (end+1)%size ; i = (i+1)%size){
        printf("%d ", cir_queue[i]);
    }
    printf("\n");
}

