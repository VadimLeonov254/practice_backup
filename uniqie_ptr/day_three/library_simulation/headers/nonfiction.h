#ifndef NONFICTION_H
#define NONFICTION_H

#include "book.h"

class Nonfiction : public Book{
private:
    std::string topic;
public:
    void printInfo();
};

#endif
