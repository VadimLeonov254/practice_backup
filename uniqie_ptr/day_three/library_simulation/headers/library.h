#ifndef LIBRARY_H
#define LIBRARY_H

#include "shelf.h"
#include<memory>
#include<vector>

class Library{
private:
    std::vector<std::unique_ptr<Shelf>> shelves;

public:
    void addShelf(std::unique_ptr<Shelf> shelf);
    void printLibrary();

};

#endif
