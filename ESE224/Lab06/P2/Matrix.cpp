
#include "Matrix.h"
#include <fstream>

#include <iostream>
using namespace std;


Matrix::Matrix(){

}

void Matrix::readFromFile(const string& filename){
    fstream InputFile(filename);

    InputFile >> row >> column;
    
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            InputFile >> matrix[i][j];
        }
    }

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }

}

// vector<int> Matrix::getSpiralOrder() const{

// }

void Matrix::writeSpiralOrderToFile(const string& filename) const{
    fstream OutputFile(filename);

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            OutputFile << matrix[i][j];
        }
    }
}