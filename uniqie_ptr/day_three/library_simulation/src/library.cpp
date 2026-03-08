#include<iostream>
#include<memory>
#include<vector>
#include "shelf.h"
#include "book.h" 
#include "library.h"

void Library::addShelf(std::unique_ptr<Shelf> shelf){
    shelves.push_back(std::move(shelf));
}

void Library::printLibrary(){
    for(int i = 0; i < shelves.size(); i++){
        shelves[i] -> printShelf();    
    }
}
