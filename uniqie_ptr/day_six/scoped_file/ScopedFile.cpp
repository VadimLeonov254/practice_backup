#include<iostream>
#include<fstream>
#include<memory>

#include "ScopedFile.h"

ScopedFile::ScopedFile(std::string fileName, std::string action) {
    
    file = std::make_unique<std::fstream>(fileName, std::ios::in | std::ios::out | std::ios::app);
    open = file->is_open();
}

bool ScopedFile::isOpen(){
    return open;
}

std::string ScopedFile::readLine(){
    if(file->is_open()){
        std::string line;
        std::getline(*file, line);  
        return line;
    }else{
        return "The file is closed, nothing to read!\n";
    }
}

void ScopedFile::writeLine(const std::string& line){
    if(file->is_open()){
        *file << line << std::endl;
    }
}


