#pragma once
#include <iostream>
#include <string>

class BankAccount
{
private:
    double balance;
    std::string accountHolderName;

public:
    double getBalance()
    {
        return balance;
    }

    std::string getAccountHolderName()
    {
        return accountHolderName;
    }

    void setBalance(int b)
    {
        balance = b;
    }

    void setAccountHolderName(std::string n)
    {
        accountHolderName = n;
    }

    void displayInfo()
    {
        std::cout << "Account Holder Name: " << accountHolderName << std::endl;
        std::cout << "Account Balance: " << balance << std::endl;
    }

    void deposit(double add)
    {
        balance = balance + add;
    }

    void withdrawal(double subtract)
    {
        balance = balance - subtract;
    }
};
