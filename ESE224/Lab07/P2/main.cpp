
#include <fstream>
#include <iostream>

using namespace std;

void calculateStats(int* arr, int size, int &max, int &min, double &average) {
    int sum = 0;
    max = *arr;
    min = *arr;

    for (int* ptr = arr; ptr < arr + size; ptr++) {
        if (*ptr > max) max = *ptr;      // Update max
        if (*ptr < min) min = *ptr;      // Update min
        sum += *ptr;                     // Sum for average calculation
    }
    average = (1.0 * sum) / size;

}

int main(){
    ifstream InputFile("input.txt");
    ofstream OutputFile("output.txt");

    int data, size = 0, numbers[1000];


    while (InputFile >> numbers[size]) {
        size++;
    }
    InputFile.close();



    OutputFile << "Original Array: ";
    for(int i = 0 ; i < size ; i++){
        OutputFile << numbers[i] << " ";
    }
    OutputFile << endl;

    int max, min;
    double average;
    calculateStats(numbers, size, max, min, average);

    OutputFile << "Maximum: " << max << endl;
    OutputFile << "Minimum: " << min << endl;
    OutputFile << "Average: " << average << endl;

    OutputFile.close();

    return 0;
}