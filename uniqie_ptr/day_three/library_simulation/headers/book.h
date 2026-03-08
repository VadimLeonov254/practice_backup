#ifndef BOOK_H
#define BOOK_H

class Book{

protected:
    std::string title;

public:
   
    std::string getTitle(){
        return title;
    }
    
    void setTitle(std::string t){
        title = t;
    }

    virtual void printInfo() = 0;
    virtual ~Book() = default;
};

#endif
