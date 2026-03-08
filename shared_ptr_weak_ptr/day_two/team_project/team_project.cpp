#include<iostream>
#include<memory>

struct Project;

struct Team{
    std::shared_ptr<Project> project;
    ~Team(){
        std::cout << "Team has been destroyed" << '\n';
    }
};

struct Project{
    std::weak_ptr<Team> team;
    ~Project(){
        std::cout << "Project has been destroyed" << '\n';
    }

};

int main(){
    
    auto team = std::make_shared<Team>();
    auto project = std::make_shared<Project>();

}
