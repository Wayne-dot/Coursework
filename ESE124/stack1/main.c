#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// extern int top_stack;

int main(int argc, char *argv[]){
    char c = 'C';
    int value;
    reset();

    while(c != 'x'){
        printf("x/p/t/o/r: ");
        scanf("%c", &c); getchar();

        switch (c)
        {
            case 'x': return;
            case 't': printf("top is %d\n", top()); break;
            case 'p': printf("Value "); scanf("%d", &value);
                      
            case 'o': pop(); break;
            case 'r': reset(); break;
            
            default: printf("Warning: %c is in correct", c); break;
               
        }
    }

    return 0;
}