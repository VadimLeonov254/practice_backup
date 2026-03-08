#include<iostream>
#include "media.h"

MediaLibrary::MediaLibrary(int size) : size(size){
    title = new char[size];
}

MediaLibrary::~MediaLibrary(){
    delete[] title;
}

MediaLibrary::MediaLibrary(const MediaLibrary& other){
    size = other.size;
    title = new char[size];
    for(int i = 0; i < size; i++){
        title[i] = other.title[i];
    }
}

void MediaLibrary::printInfo(){
    for(int i = 0; i < size; i++){
        std::cout << title[i];
    }
    std::cout << std::endl;
}

void MediaLibrary::giveTitle(std::string name){
    for (int i = 0; i < size; i++){
        title[i] = name[i];
    }
}

Song::Song(int duration, std::string name, int size) : MediaLibrary(size), duration(duration), name(name) {}

void Song::getSong(){
    std::cout << name << " has duration of " << duration << " seconds." << std::endl;
}

