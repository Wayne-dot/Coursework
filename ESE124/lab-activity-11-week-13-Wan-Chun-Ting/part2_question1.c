#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the struture of the person information
typedef struct
{
    char firstname[32];
    char lastname[32];
    int zipcode;
    int age;
    float GPA;
} Person;

void display(Person *person, int r){
    for(int i = 0 ; i < r ; i++){
        printf("%s %s %d %d %f\n", person[i].firstname, person[i].lastname, person[i].zipcode, person[i].age, person[i].GPA);
    }
}

void gpa_order(Person *person, int r){
    Person temp;
    // bubble sprt in decreasing order
    for(int i = 0 ; i < r - 1; i++){
        for(int j = 0 ; j < r - i - 1; j++){
            if(person[j+1].GPA > person[j].GPA){
                temp = person[j+1];
                person[j+1] = person[j];
                person[j] = temp;
            }
        }
    }

    printf("\n");
}

// orders the array in alphabetic order of the person’s last name.
void lastname_sort(Person *person, int r){
    Person temp;
    for(int i = 0 ; i < r - 1; i++){
        for(int j = 0 ; j < r - i - 1; j++){
            if(strcmp(person[j+1].lastname, person[j].lastname) < 0){
                temp = person[j+1];
                person[j+1] = person[j];
                person[j] = temp;
            }
        }
    }
    printf("\n");
}

//reads a zip code from the keyboard and then displays all the persons with this zipcode
void readdisplay_read(Person *person, int r){
    int zip;
    printf("Input zip code: ");
    scanf("%d", &zip);

    for(int i = 0 ; i < r ; i++){
        if(zip == person[i].zipcode){
            printf("%s %s %d\n", person[i].firstname, person[i].lastname, person[i].zipcode);
        }
    }
    printf("\n");
}


int main(){
    FILE *fin;
    fin = fopen("input.txt", "r");

    if(fin == NULL){
        printf("input.txt not found");
        exit(1);
    }

    int row;

    fscanf(fin, "%d", &row);
    fgetc(fin);

    Person *persons = (Person*) malloc(row * sizeof(Person));

    for(int i = 0 ; i < row ; i++){
        fscanf(fin, "%s %s %d %d %f", &persons[i].firstname, &persons[i].lastname, &persons[i].zipcode, &persons[i].age, &persons[i].GPA);
    }

    // Write a main program that repeatedly reads and implements the following commands: D for the
    // function at step 2; O for the function at step 3; A for the function at step 4; Z for the function at step 5
    
    char c;

    while(1){
        printf("Operation: ");
        scanf("%c", &c); getchar();

        if(c == 'D'){
            display(persons, row);
        }
        else if(c == 'O'){
            gpa_order(persons, row);
        }
        else if(c == 'A'){
            lastname_sort(persons, row);
        }
        else if(c == 'Z'){
            readdisplay_read(persons, row);
        }
    }
    
    return 0;
}