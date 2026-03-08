#include<iostream>
#include "Document.h"

Document::Document(std::string title) : title(title) {}

void Document::read(){
    if(content.size() == 0){
        std::cout << "The document is empty, nothing to read" << '\n';
    }else{
        std::cout << content << '\n';
    }
};

void Document::write(std::string text){
    if(isLocked == true){
        if(content.size() == 0){
            content = text;
        }else{
            content += text;
        }
    }else{
        std::cout << "Unable to write in the document" << '\n';
    }
};

void Document::toggleLock(){
    isLocked = !isLocked;
};

bool Document::getLocked(){
    return isLocked;
};
