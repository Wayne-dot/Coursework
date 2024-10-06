

#include <string>

using namespace std;

class Employee{
    private:
        string name;
        int id;
        double base_salary;
        double updatedSalary;
        int rate;
    public:
        void calculateSalary();
        void setEmployeeData(string n_ame, int i_d, double base, int rat);
        double getUpdatedSalary();
};