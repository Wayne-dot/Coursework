#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    int *p;
    char *c;

    printf("How many data? ");
    scanf("%d", &a);

    p = (int *) malloc(a * sizeof(int));
    c = (char *) malloc(a * sizeof(char));

    free(p);

}