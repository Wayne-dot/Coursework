#include <stdio.h>

#define MAX 50

int main(){
	FILE *fin, *fout;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	char c;
	char c_list[MAX];
	char unique[MAX];
	int occur[MAX];
	int i, j;
	
	
	if((fin == NULL)|| (fout == NULL)){
		printf("Found not found");
	}
	
	c = fgetc(fin);
	
	i = 0;
	while(c != EOF){
		if(c >= 'A' && c <= 'Z'){
			c += 32;
		}
		
		c_list[i] = c;
		i += 1;
		
		c = fgetc(fin);
	}
	
	int counter = i;
	
	for(i = 0 ; i < counter; i++){
		printf("%c", c_list[i]);
	}
	
	
	
	return 0;
}
