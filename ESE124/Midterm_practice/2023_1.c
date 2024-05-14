// 1.	(40 pts) Write a C program that uses two 1D arrays of decimal values to produce a third 1D array of decimal values that contains only the common values of the two arrays. 
// The two 1 D arrays can have each at most 12 values. The values of the first 1D array are read from the input file “File1.txt”, 
// and the values of the second 1D array are read from the input file “File2.txt”. The third 1 D array is written into an output file called “File3.txt”.

// Input example: First 1D array is 2.0  5.0  3.0  4.0,  and second 1D array is 3.0  5.0  7.0  8.0
// Then, the third 1D array (result) is 5.0  3.0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 12

int main(){
    FILE *fin1, *fin2, *fin3;
    float first[MAX], second[MAX], final[MAX];
    float num;
    int i = 0, j = 0, q = 0;

    fin1 = fopen("File1.txt", "r");
    fin2 = fopen("File2.txt", "r");
    fin3 = fopen("File3.txt", "w");

    if(fin1 == NULL || fin2 == NULL || fin3 == NULL){
        printf("Files not found");
        exit(1);
    }

    while (fscanf(fin1, "%f", &num) != EOF){
        first[i] = num;
        i++;
    }

    while((fscanf(fin2, "%f", &num)) != EOF){
        second[j] = num;
        j++;
    }

    for(int k = 0; k < i ; k++){
        for(int z = 0; z < j; z++){
            if (first[k] == second[z]){
                final[q] = first[k];
                q++;
            }
        }
    }

    for(int i = 0 ; i < q; i++){
        printf("%.2f\n", final[i]);
        fprintf(fin3, "%.1f ", final[i]);
    }




    return 0;
}