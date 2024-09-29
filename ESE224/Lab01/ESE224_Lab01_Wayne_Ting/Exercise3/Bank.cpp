

#include "Bank.h"

#include <iostream>
using namespace std;

BankAccount::BankAccount() : accountNumber(""), holderName(""), balance(0.0){

}

BankAccount::BankAccount(string accNum, string name, double bal): accountNumber(accNum), holderName(name), balance(bal){

}

void BankAccount::deposit(double amount){
    if(amount >= 0){
        balance = balance + amount;
    }
    else{
        cout << "Attempts to deposite negative amount, fail operation" << endl;
    }
}

void BankAccount::withdraw(double amount){
    if (amount > balance){
        cout << "Attempts to withdraw " << amount << " Fail attempts" << endl;
    }
    else{
        balance = balance - amount;
    }
}

double BankAccount::getBalance() const{
    return balance;
}