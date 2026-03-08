#include<iostream>
#include "dyn_class.h"

int main(){
    
    int len, a;
    
    std::cout << "Enter the size of the array: ";
    std::cin >> len;
    
    Buffer arr = Buffer(len);

    std::cout << "Enter " << len << " numbers below:" << std::endl;
    for(int i = 0; i < len; i++){
            std::cin >> a;
            arr[i] = a;
    }

    arr.print();

}
