#include<iostream>
#include<memory>
#include<vector>
#include "book.h" 
#include "shelf.h"

void Shelf::addBook(std::unique_ptr<Book> book){
    books.push_back(std::move(book));
} 

void Shelf::printShelf(){
    for(int i = 0; i < books.size(); i++){
        std::cout << books[i] -> getTitle() << std::endl;
    }
}


