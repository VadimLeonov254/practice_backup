#include<iostream>
#include<memory>
#include"File.h"

File::File(int num) : num(num) {}

int File::getNum(){
    return num;
}

File::~File(){
    std::cout << "File has been destroyed" << '\n';
}

