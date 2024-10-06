//
//  main.cpp
//  Lab04
//
//  Created by Wayne Ting on 10/2/24.
//

#include <iostream>
#include <fstream>

using namespace std;

void fakeIncrement(int num){
    num += 1;
}

void incremnt(int &num){
    num +=1;
}

int main(int argc, const char * argv[]) {
    
    ifstream inputFile("input.txt");
    ofstream outputFile("output_fake_increment.txt");
    
    if(!inputFile || !outputFile){
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }
    
    
    int number;
    while(inputFile >> number){
        // or fakeIncrement
        fakeIncrement(number);
        cout << number << endl;
        outputFile << number << endl;
    }
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}
