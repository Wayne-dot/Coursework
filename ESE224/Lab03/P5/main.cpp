
#include <fstream>
#include <iostream>

using namespace std;

int fib(int x){
    if(x <= 1){
        return x;
    }
    return fib(x - 1) + fib(x - 2);
}

int main(){

    ifstream inputfile("fib_input.txt");
    ofstream outputfile("fib_output.txt");

    if(!inputfile || !outputfile){
        cout << "File can not be open" << endl;
    }

    int input_num;
    while(!inputfile.eof()){
        inputfile >> input_num;
        outputfile <<  "Fibonacci of " << input_num << " is " << fib(input_num) << endl; 
    }



    return 0;
}

