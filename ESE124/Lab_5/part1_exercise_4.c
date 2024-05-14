#include <stdio.h>

int main(){
	FILE *fin;
	char c;
	int pos = 0, zero = 0, neg = 0;
	int num;
	fin = fopen("input.txt", "r");
	
	if(fin == NULL){
		printf("Found not found");
	}
	
		
	while(fscanf(fin, "%d", &num) != EOF){
		if(num == 0){
			zero +=1;
		}
		else if (num < 0){
			neg += 1;
		}
		else{
			pos += 1;
		}

		
	}
	
	printf("Posistive %d, negative %d, zero %d", pos, neg, zero);
	
	return 0;
}
