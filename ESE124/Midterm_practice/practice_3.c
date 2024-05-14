// Write a program in C to display the n terms of harmonic series and their sum.
// 1 + 1/2 + 1/3 + 1/4 + 1/5 ... 1/n terms


#include <stdio.h>

int main(){
    int n;
    float sum = 0.0;
    float temp = 0.0;

    printf("Input numner of n term: ");
    scanf("%d", &n);


    for(int i = 1 ; i < n + 1; i++){
        temp = 1.0/i;
        printf("%f\n", temp);
        sum = sum + temp;
    }

    printf("Sum is %.2f", sum);
    
    return 0;
}