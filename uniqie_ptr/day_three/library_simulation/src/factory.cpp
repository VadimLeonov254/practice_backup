#include<iostream>
#include<memory>
#include<vector>

#include "factory.h"
#include "book.h"
#include "fiction.h"
#include "nonfiction.h"

std::unique_ptr<Book> Factory::createBook(std::string type, std::string name){
    
    std::unique_ptr<Book> book;

    if(type == "fiction"){
        book = std::make_unique<Fiction>();
    } else if(type == "nonfiction"){
        book = std::make_unique<Nonfiction>();
    }

    book -> setTitle(name);

    return book;

} 
