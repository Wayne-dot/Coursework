
#include "Employee.h"

void Employee::calculateSalary(){
    if(rate == 2){
        updatedSalary = base_salary*1.02;
    }
    else if (rate == 3) {
        updatedSalary = base_salary*1.05;
    }
    else if (rate == 4) {
        updatedSalary = base_salary*1.07;
    }
    else if (rate == 5) {
        updatedSalary = base_salary*1.1;
    }
    else{
        updatedSalary = base_salary;
    }
}

void Employee::setEmployeeData(string n_ame, int i_d, double base, int rat){
    name = n_ame;
    id = i_d;
    base_salary = base;
    rate = rat;
}

double Employee::getUpdatedSalary(){
    return updatedSalary;
}