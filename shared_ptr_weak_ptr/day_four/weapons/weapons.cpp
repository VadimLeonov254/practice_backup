#include<iostream>
#include<memory>
#include<vector>


struct Weapon{
    ~Weapon(){
        std::cout << "Weapon has been destroyed" << '\n';
    }
};

struct Player{
    std::vector<std::unique_ptr<Weapon>> player;
    ~Player(){
        std::cout << "Player has been destroyed" << '\n';
    }
};

struct Inventory{
    std::weak_ptr<Player> inventory;
    ~Inventory(){
        std::cout << "Inventory has been destroyed" << '\n';
    }  
}; 

int main(){
    auto weapon_pistol = std::make_unique<Weapon>();
    auto weapon_machine_gun = std::make_unique<Weapon>();
    auto player = std::make_shared<Player>();
    auto inventory = std::make_shared<Inventory>();

    inventory -> inventory = player;

    player -> player.push_back(std::move(weapon_pistol));
    player -> player.push_back(std::move(weapon_machine_gun));

}
