#include<iostream>
#include<memory>
#include"File.h"
#include"FileManager.h"

int main(){
    
    FileManager myManager;

    auto file = std::make_unique<File>(12);
    auto file_2 = std::make_unique<File>(14);


    myManager.addFile(std::move(file));
    myManager.addFile(std::move(file_2));

    std::cout << myManager.fileCount() << '\n';
    
    myManager.deleteFile();

    std::cout << myManager.fileCount() << '\n';

}
