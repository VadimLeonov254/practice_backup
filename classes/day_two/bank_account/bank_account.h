#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H


class BankAccount{

private: 
    int accountBalance;
    int accountNumber;

public:
    BankAccount(int accountBalance, int accountNumber = 123);
    int getBalance();
    void withdraw(int money);
    void deposit(int money);

};



#endif 
