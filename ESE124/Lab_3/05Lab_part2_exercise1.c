#include <stdio.h>

int main(){

    int pos_num = 0;
    int neg_num = 0;
    int zero_num = 0;

    int input_num;
    int input_num_2;

    printf("Enter a number: ");
    scanf("%d", &input_num);


    if(input_num > 0){
            pos_num += 1;
    }
    else if(input_num< 0){
        neg_num += 1;
    }
    else{
        zero_num += 1;
    }

    int flag = 1;

    while (flag)
    {
        printf("Enter a number: ");
        scanf("%d", &input_num_2);
        printf("\n");

        if(input_num_2 == input_num){
            break;
        }

        if(input_num_2 > 0){
            pos_num += 1;
        }
        else if(input_num_2 < 0){
            neg_num += 1;
        }
        else{
            zero_num += 1;
        }

        printf("\n");
        printf("Number of positive numbers: %d\n", pos_num);
        printf("Number of negative numbers: %d\n", neg_num);
        printf("Number of zero numbers: %d\n", zero_num);
        input_num = input_num_2;
    }


    return 0;
}