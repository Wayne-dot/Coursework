#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Info {
    char title[100];
    int credit;
    char instructor[100];
    int suggest_order;
} Info;


int main(){
    FILE *fin1, *fin2;
    char line[100];
    int row = 0;

    fin1 = fopen("input.txt", "r");
    fin2 = fopen("input.txt", "r");


    if(fin1 == NULL || fin2 == NULL){
        printf("input.txt file not found\n");
        exit(1);
    }

    while((fgets(line, 100, fin1)) != NULL){
        row += 1;
    }
    fclose(fin1);

    Info *all_info = (Info*) malloc(row * sizeof(Info));

    int count = 0;
    int round = 0;
    
    for(int i = 0 ; i < row ; i++){
        fscanf(fin2, "%s %d %s %d", all_info[i].title, &all_info[i].credit, all_info[i].instructor, &all_info[i].suggest_order);
    }

    for(int i = 0 ; i < row ; i++){
        printf("%s %d %s %d\n", all_info[i].title, all_info[i].credit, all_info[i].instructor, all_info[i].suggest_order);
    }
    printf("\n");


    Info temp;

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < row - i - 1; j++){
            if(strcmp(all_info[j].title, all_info[j+1].title) > 0){
                temp = all_info[j];
                all_info[j] = all_info[j+1];
                all_info[j+1] = temp;
            }
        }
    }

    for(int i = 0 ; i < row ; i++){
        printf("%s %d %s %d\n", all_info[i].title, all_info[i].credit, all_info[i].instructor, all_info[i].suggest_order);
    }
    printf("\n");

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < row - i - 1; j++){
            if(all_info[j].suggest_order > all_info[j+1].suggest_order){
                temp = all_info[j];
                all_info[j] = all_info[j+1];
                all_info[j+1] = temp;
            }
        }
    }

    for(int i = 0 ; i < row ; i++){
        printf("%s %d %s %d\n", all_info[i].title, all_info[i].credit, all_info[i].instructor, all_info[i].suggest_order);
    }
    printf("\n");


    fclose(fin2);
    free(all_info);
    
}