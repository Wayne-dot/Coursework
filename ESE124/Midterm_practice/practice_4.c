// 4.	Write a program in C to display the sum of the series [ 9 + 99 + 999 + 9999 ...]

#include <stdio.h>

int main(){
    int sum = 0;
    int temp;
    int n;
    int muti = 1;

    printf("Nth term: ");
    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        temp = 0;
        for(int j = 0 ; j < i ; j++){
                temp += 9*muti;
                muti *= 10;
        }
        muti = 1;
        sum += temp;
    }
    printf("Result is %d", sum);
    
    return 0;
}