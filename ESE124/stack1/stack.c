#include <stdio.h>


#define MAX_SIZE 100

// global variable
static int stackdata[MAX_SIZE];
static int top_stack, top;

// reset stack by setting top to 0
void reset(){
    top = 0;
}

int empty (){
    if(top_stack == 0){
        return 1;
    }
    else{
        return 0;
    }
}

// full return 1 if the stack is full, and 0 otherwise

int full(){
    if(top_stack == MAX_SIZE){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int a){
    if(!full()){
        stack_data[top_stack] = a;
        top_stack++;
    }
    else{
        printf("Error: stack is full\n");
        exit(1);
    }
}

void pop(){
    if(!empty()){
        top_stack--;
    }
    else{
        printf("Error: stack is empty\n");
        exit(1);
    }
}

int top(){
    if(!empty()){
        return stackdata[top_stack-1];
    }
    else{
        printf("error: stack is empty\n");
        exit(1);
    }

}