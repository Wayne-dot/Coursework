#define MAXESIZE 100

extern int count, score;

void actions(char *str, FILE *faction, int *step_number_pointer, int row, int column, char maze[][MAXESIZE], int current_position[2], char list_of_perform_action[][1000]);
