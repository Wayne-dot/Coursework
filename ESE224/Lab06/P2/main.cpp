
#include "Matrix.h"



int main(){
    Matrix matrix;

    matrix.readFromFile("matrix_input.txt");

    matrix.writeSpiralOrderToFile("matrix_output.txt");
    
    return 0;
}