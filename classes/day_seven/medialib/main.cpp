#include<iostream>
#include "media.h"

int main(){
    
    int size;
    std::string name;
    std::cout << "Enter size: ";
    std::cin >> size;
    
    std::cout << "Enter the name: ";
    std::cin >> name;
    MediaLibrary player = MediaLibrary(size);

    player.giveTitle(name);

    player.printInfo();

}
