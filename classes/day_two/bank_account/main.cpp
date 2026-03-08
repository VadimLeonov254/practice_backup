#include<iostream>
#include "bank_account.h"


int main(){
    BankAccount bank(1000);

    std::cout << "Current balance is " << bank.getBalance() << std::endl;

    bank.deposit(456);

    std::cout << "Current balance is " << bank.getBalance() << std::endl;

    bank.withdraw(111);

    std::cout << "Current balance is " << bank.getBalance() << std::endl;


}
