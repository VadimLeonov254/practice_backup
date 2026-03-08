#include<iostream>
#include "bank_account.h"


BankAccount::BankAccount(int accountBalance, int accountNumber) : accountBalance(accountBalance), accountNumber(accountNumber) {}


int BankAccount::getBalance(){
    return accountBalance;
}


void BankAccount::withdraw(int money){
    accountBalance -= money;
}

void BankAccount::deposit(int money){
    accountBalance += money;
}
