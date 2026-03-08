#ifndef SHELF_H
#define SHELF_H

#include "book.h"
#include<memory>
#include<vector>


class Shelf{
private:
    std::vector<std::unique_ptr<Book>> books;

public:
    void addBook(std::unique_ptr<Book> book);    
    void printShelf();
};

#endif
