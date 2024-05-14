#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

#define MAX_SIZE 1000

int cir_queue[MAX_SIZE];
int front, end, size, k;

int main(){

    int remove[MAX_SIZE];

    printf("Input Sequence\n");
    printf("Array Max Size: ");
    scanf("%d", &size);
    printf("k: ");
    scanf("%d", &k);

    init(size);
    pop();
    print_queue();
    
    int a = first();
    int j = 0;

    while(!one_left()){

        for(int i = 0 ; i < k - 1 ; i++){
            a = first();
            pop();
            add(a);
        }
        remove[j] = first();
        j++;
        pop();
        print_queue();
    }
    printf("\n");

    printf("Output Sequence\n");

    printf("Persons removed: ");
    for(int i = 0 ; i < j ; i++){
        printf("%d ", remove[i]);
    }
    printf("\n");

    printf("Person survive: %d", first());

    return 0;
}