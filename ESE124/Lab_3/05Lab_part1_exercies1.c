#include <stdio.h>

int main(){

    float decimal;
    float positive = 0;
    float negative = 0;
    int a = 0;
    int pos = 0;
    int neg = 0;

    while (a < 15)
    {
        printf("Please input a decimal value: ");
        scanf("%f", &decimal);

        if(decimal > 0){
            pos += 1;
            positive += decimal;
        }
        else if (decimal < 0){
            neg += 1;
            negative += decimal;
        }
        a += 1;
    }


    if (pos == 0)
    {
        printf("No positive number entered");
    }
    else{
        printf("Average of Positive Numbers %f\n", positive/pos);
    }

    if (neg == 0)
    {
        printf("No negative number entered");
    }
    else{
        printf("Average of Negative Numbers %f\n", negative/neg);
    }
    
    
    return 0;
}