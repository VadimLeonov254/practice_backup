#ifndef FACTORY_H
#define FACTORY_H

#include<memory>
#include "book.h"

class Factory{
public:
    std::unique_ptr<Book> createBook(std::string type, std::string name);
};

#endif
