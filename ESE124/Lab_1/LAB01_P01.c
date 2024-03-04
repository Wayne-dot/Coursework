//Wayne Ting SBU ID: 115334926

#include <stdio.h>
#include <math.h>

int main() {
	
	while(1){
//		intitize integer for day, month and year
		int day;
		int month;
		int year;
		
//		instruction and getting input from the user
		printf("Input: ");
		scanf("%d/%d/%d", &month, &day, &year);
		
//		output the format, %02d mean integer that limit to 2 integer
		printf("%02d-%02d-%04d\n", month, day, year);	
	}
	return 0;
}
