#include<iostream>
#include "dyn_class.h"

Buffer::Buffer(int size) : size(size){
    data = new int[size];
}

Buffer::~Buffer(){
    delete[] data;
}

Buffer::Buffer(const Buffer& other){
    size = other.size;
    data = new int[size];
    for(int i = 0; i < size; i++){
        data[i] = other.data[i];
    }
}

void Buffer::print(){
    std::cout << "Your array is:" << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
