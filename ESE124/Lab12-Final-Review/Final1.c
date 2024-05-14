#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// return length of the longest subseuence of the array
int find_length_increasing(int a[], int size){
    
    int old_length = 0;
    int new_length = 0;
    int j;

    for(int i = 0 ; i < size ; i++){
        if(a[i] == a[i+1] - 1){
            old_length += 1;
            for(j = i+1 ; j < size - 1; j++){
                if(a[j] == a[j+1] - 1){
                    if((a[j+1] == a[size - 1] && a[j+1] == a[j] + 1)){
                        old_length += 2;
                    }
                    else{
                        old_length += 1;
                    }
                }
                if(a[j] == a[j-1] + 1){
                    old_length += 1;
                }
                else{
                    break;
                }
            }
            
        }
        if(old_length > new_length){
            new_length = old_length;
        }
        old_length = 0;
    }
    return new_length;
}


int main(){
    int test1[] = {5, 3, 6, 7, 8, 9}; //4
    int test2[] = {1, 2, 3, 0, 2, 6}; //3
    int test3[] = {7, 3, 2, 1, 1, 2}; //2
    int test4[] = {1, 2, 5, 6, 7, 8, 9}; //5



    printf("Result is %d\n", find_length_increasing(test2, 6));

    return 0;
}