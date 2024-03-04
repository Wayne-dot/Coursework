#include <stdio.h>


// Design a C program that reads decimal numbers from the keyboard. The program reads at
// least three numbers. Find and display the smallest number, the second smallest number, and the third
// smallest number of the set. The program ends if the largest number encountered does not change for n
// iterations (such as the largest number does not change for the next n numbers since it changed). The
// value of n is read from the keyboard. Value n is greater or equal to 3.


// {2, 4, 5, 10, 100}
// Need 2, 4, 5, 100

// {3}
// {3, 6}
// 3 6 6 6
// 3 6 6 9
// 3 6 7 9
// 3 6 7 10


int main(){
    
    int count = 0;
    int check = 0;

    float smallest;
    float sec_small;
    float third_small;
    float largest;

    float previous_largest;

    float temp;

    int n;


    printf("Enter the number of iterations(n), should be greater than or equal to 3: ");
    scanf("%d", &n);
    printf("\n");

    do
    {
    	printf("Enter a decimal numbers: ");
    	if(count == 0){
    		scanf("%f", &smallest);
    		sec_small = third_small = largest = smallest;
		}
		
		else
		{
			scanf("%f", &temp);
			
			if (temp >= largest)
	        {
	            largest = temp;
	        }
	    	
	        
	        if(previous_largest == largest){
	        	check ++;
			}
			if(previous_largest != largest){
				check = 0;
				previous_largest = largest;
			}
			
	        
	        
	        
	        if (temp <= smallest) {
	            third_small = sec_small;
	            sec_small = smallest;
	            smallest = temp;
	        } 
	        else if(smallest == sec_small && sec_small == third_small && temp > third_small){
	            sec_small = temp;
	            third_small = temp;
	        }
	
			else if (temp <= sec_small) {
	            third_small = sec_small;
	            sec_small = temp;
	        }
	        
	        else if (temp <= third_small) {
	            third_small = temp;
	        } 
	
	        else if (temp > largest) {
	            largest = temp;
	        }
    	}
    	count++;
        
        printf("Count: %d - Smallest: %.2f - second_smallest: %.2f - third_smallest: %.2f - Largest: %.2f\n\n", count, smallest, sec_small, third_small, largest);
          
        
    } 
    while (check < n-1);
    
    return 0;
}
