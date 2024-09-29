
#ifndef BANK_H
#define BANK_H

#include <string>
using namespace std;

class BankAccount{
    private:
        string accountNumber;
        string holderName;
        double balance;
    public:
        BankAccount();
        BankAccount(string accNum, string name, double bal);

        void deposit(double amount);
        void withdraw(double amount);
        double getBalance() const;
};

#endif