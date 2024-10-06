
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Employee.h"

using namespace std;

int main(){

    ifstream InputFile("input.txt");
    ofstream OutputFile("output.txt");

    if(!InputFile || !OutputFile){
        cerr << "Can not open file" << endl;
        return 1;
    }

    int num_of_line;

    InputFile >> num_of_line;
    InputFile.ignore();  //ignore the new line character
    cout << num_of_line << endl;

    string line, name, id_str, rate_str, base_str;
    int id, rate;
    double base;

    for(int i = 0 ; i < num_of_line ; i++){
        getline(InputFile, line);
        stringstream ss(line);
        //This line reads a substring from the stringstream ss up to the first occurrence of the delimiter , (a comma in this case) and stores that substring in the variable {name}.
        getline(ss, name, ',');
        getline(ss, id_str, ',');
        getline(ss, base_str, ',');
        getline(ss, rate_str, ',');

        id = stoi(id_str); //string to int
        base = stod(base_str); //string to double
        rate = stoi(rate_str); //string to int

        Employee employee;
        employee.setEmployeeData(name, id, base, rate);
        employee.calculateSalary();

        OutputFile << name << " (ID: "<< id << ") - Updated Salary: " << employee.getUpdatedSalary() << endl;
    }


    return 0;
}