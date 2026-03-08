#include<iostream>

int main(){

    int size, a;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr_a = new int[size];
    int* arr_b = new int[size];

    std::cout << "Enter " << size << " numbers" << std::endl;

    for(int i = 0; i < size; i++){
        std::cin >> a;
        arr_a[i] = a;
    }

    for(int i = 0; i < size; i++){
        arr_b[i] = arr_a[size-1-i];
    }
    
    std::cout << "Your array is: ";

    for(int i = 0; i < size; i++){
        std::cout << arr_a[i] << " ";
    }
    std::cout << std::endl;

    
    std::cout << "Your reversed array is: ";

    for(int i = 0; i < size; i++){
        std::cout << arr_b[i] << " ";
    }
    std::cout << std::endl;

}
