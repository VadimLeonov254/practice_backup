#ifndef FICTION_H
#define FICTION_H

#include "book.h"

class Fiction : public Book{
private:
    std::string genre;
public:
    void printInfo();
};

#endif
