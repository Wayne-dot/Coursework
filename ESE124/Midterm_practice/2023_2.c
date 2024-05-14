// The program reads decimal values from an input file called “Input_file.txt” and stores the values in a vector (1D array). The input file can contain at most 15 values. 
// The program must reverse the values in the 1 D array. Then, it should display the largest, the third largest, and the fifth largest value of the 1 D array, assuming that there are more than five values in the 1D array.
// All output results are stored in an output file called “output_file.txt

// bubble sort
// 3, 2, 4, 5, 1

//0, 1, 2, 3
// 3, 2, 1, 0

#include <stdio.h>
#include <stdlib.h>

#define MAX 15

int main(){
    FILE *fin1, *fin2;
    float num, temp;
    int i = 0;
    float file1[MAX];

    fin1 = fopen("Input_file.txt", "r");
    fin2 = fopen("Output_file.txt", "w");

    if(fin1 == NULL || fin2 == NULL){
        printf("File not found");
        exit(1);
    }

    while((fscanf(fin1, "%f", &num)) != EOF){
        file1[i] = num;
        i++;
    }

    for(int j = 0; j < i/2; j++){
        temp = file1[j];
        file1[j] = file1[i - 1 - j];
        file1[i - 1 - j] = temp;
    }


    // largest, the third largest, and the fifth largest 
    // sort
    for(int j = 0; j <= i - 2; j++){
        for(int k = 0; k <= (i - 2 - j) ; k++){
            if(file1[k] > file1[k+1]){
                temp = file1[k+1];
                file1[k+1] = file1[k];
                file1[k] = temp;
            }
        }
    }

    for(int j = 0; j < i; j++){
        printf("%.2f\n", file1[j]);
    }

    printf("Largest: %.2f\n", file1[i-1]);
    printf("Third Largest: %.2f\n", file1[i-3]);
    printf("Fifth Largest: %.2f\n", file1[i-5]);
    
    
    return 0;
}