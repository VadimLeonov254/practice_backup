#include<iostream>

int* arrAlloc(int size){
    int* data = new int[size*size];
    return data;
}

int main(){
    
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;

    std::cout << "Array which is double the size of the number you've just entered is at this address: " << arrAlloc(n) << std::endl;
   
    


}
