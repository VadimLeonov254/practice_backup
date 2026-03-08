#include<iostream>
#include<memory>
#include<vector>
#include "FileManager.h"
#include"File.h"

FileManager::FileManager(){}

int FileManager::fileCount(){
    return files.size();
}

void FileManager::addFile(std::unique_ptr<File> file){
    files.push_back(std::move(file));
}

void FileManager::deleteFile(){
    files.pop_back();
}

