#include<iostream>
#include<memory>

struct Session;

struct User{
    std::shared_ptr<Session> session;
    ~User(){
        std::cout << "User has been destroyed" << '\n';
    }

};

struct Session{
    std::weak_ptr<User> user;
    ~Session(){
        std::cout << "Session has been destroyed" << '\n';
    }

};

int main(){

    auto user = std::make_shared<User>();
    auto session = std::make_shared<Session>();

    user -> session = session;
    session -> user = user;

}
