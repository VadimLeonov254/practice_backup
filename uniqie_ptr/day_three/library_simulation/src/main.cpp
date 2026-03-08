#include<iostream>
#include<memory>

#include "shelf.h"
#include "library.h"
#include "factory.h" 

int main(){
    
    Shelf bottomShelf;
    Factory myFactory;

    bottomShelf.addBook(myFactory.createBook("fiction", "lalala"));

    bottomShelf.printShelf();

}
