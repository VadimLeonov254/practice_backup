#ifndef DYN_CLASS_H
#define DYN_CLASS_H

class Buffer{

private:
    int* data;
    int size;

public:
    
    Buffer(int size);
    ~Buffer();

    int& operator[](unsigned int i){
        return data[i];
    }
    
    Buffer(const Buffer& other);
    void print();

};


#endif
