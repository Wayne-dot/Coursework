// Write a program in C to find the sum of the series [ x - x^3 + x^5 + ......]

#include <stdio.h>

int main(){
    int sum = 0, temp = 1, n, x;

    printf("Nth term: ");
    scanf("%d", &n);

    printf("x: ");
    scanf("%d", &x);

    sum += x;
    temp = x;

    for(int i = 1; i <= n - 1; i++){
        temp = temp*-1*x*x;
        sum += temp;
    }

    printf("\nSum: %d\n", sum);
    
    return 0;
}