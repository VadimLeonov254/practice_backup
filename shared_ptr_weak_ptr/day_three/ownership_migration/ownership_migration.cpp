#include<iostream>
#include<memory>

struct Balance{
    int balance = 1000;
};

struct Account{
    std::unique_ptr<Balance> acc_balance;
};

struct Dad{
    std::shared_ptr<Account> dad_account;
};

struct Son{
    std::shared_ptr<Account> son_account;
};


int main(){

    auto balance = std::make_unique<Balance>();
    auto account = std::make_unique<Account>();
    auto dad = std::make_shared<Dad>();
    auto son = std::make_shared<Son>();

    account -> acc_balance = std::move(balance); 
    

    dad -> dad_account = std::move(account);

    son -> son_account = dad -> dad_account;

    std::cout << dad -> dad_account -> acc_balance -> balance << '\n';
    
    std::cout << dad -> dad_account.use_count() << '\n';
}
