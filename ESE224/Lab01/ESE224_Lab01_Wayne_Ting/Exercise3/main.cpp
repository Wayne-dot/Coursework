


#include "Bank.h"
#include <iostream>

using namespace std;

int main(){

    BankAccount account1("12345", "John Doe", 1000.0);
    account1.deposit(500);
    account1.withdraw(200);
    account1.withdraw(1500);
    account1.deposit(-100);

    cout << "Account Balance: " << account1.getBalance() << endl;
     
    return 0;
}