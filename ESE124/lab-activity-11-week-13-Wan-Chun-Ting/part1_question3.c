#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write a function that returns a pointer to the maximum value of an array of double

double *max_of_arr(double *arr, int size){
    double *max_p, *temp;
    max_p = arr;
    temp = arr + 1;

    for(int i = 0 ; i < size - 1; i++){
        if(*temp > *max_p){
            max_p = temp;
        }
        temp++;
    }

    return max_p;
}


int main(){
    double c[5] = {4.0, 5.2, 12.4, 7.9, 9.5};

    printf("Maximum is %lf", *max_of_arr(c, 5));
    
    return 0;
}