#include <iostream>
#include <string>
#include "ScopedFile.h"

int main() {
    ScopedFile myFile("example.txt", "rw");

    if(myFile.isOpen()) {
        myFile.writeLine("Hello world!");
        myFile.writeLine("This is a test.");

        std::string line;
        while(!(line = myFile.readLine()).empty()) {
            std::cout << line << std::endl;
        }
    }

    return 0;
}
