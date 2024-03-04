#include <stdio.h>
#include <limits.h>

int main(){
    int count;
    int sum = 0;
    int term = 9;
 
    
    printf("Please enter a value for n: ");
    scanf("%d", &count);

    for(int i = 0; i < count; i++){
        if(i == count - 1){
            printf("%d", term);
        }
        else{
            printf("%d + ", term);
        }
        int a = sum + term;
        if(sum > INT_MAX - term || term < 0){
            printf("\nOverflow occur before reaching %d terms", count);
            break;
        }
        else{
            sum += term;
        }
        term = (term*10) + 9;
    }
    printf("\n\n");

    if(count <= 9){
        printf("Sum of the series at %d term: %d\n", count, sum);
    }

    printf("The largest term can be calculated without error is: 9");
    return 0;


}