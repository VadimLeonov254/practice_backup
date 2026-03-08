#include <iostream>
#include <memory>
#include <string>
#include "entity.h"
#include "mover.h"

int main() {
    Mover move;
    Entity object;

    std::string input;
    float pos_x, pos_y, vel_x, vel_y;

    std::cout << "=== ENTITY SPAWN ===" << std::endl;
    std::cout << "Enter X position: ";
    std::cin >> pos_x;
    std::cout << "Enter Y position: ";
    std::cin >> pos_y;

    object.setCoord(pos_x, pos_y);

    std::cout << "Enter X velocity: ";
    std::cin >> vel_x;
    std::cout << "Enter Y velocity: ";
    std::cin >> vel_y;

    object.setVel(vel_x, vel_y);

    std::cout << std::endl << "Controls: w a s d | q to quit" << std::endl;

    while (true) {
        object.getPos();
        std::cout << "Move: ";
        std::cin >> input;

        if (input == "q") break;

        if (input == "w") object.setVel(0.0f, 1.0f);
        else if (input == "s") object.setVel(0.0f, -1.0f);
        else if (input == "a") object.setVel(-1.0f, 0.0f);
        else if (input == "d") object.setVel(1.0f, 0.0f);
        else continue;

        move.linearMovement(object);
    }

    std::cout << "Game Over" << std::endl;
}
