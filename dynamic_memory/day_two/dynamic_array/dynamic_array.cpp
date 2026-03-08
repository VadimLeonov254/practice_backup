#include<iostream>

int main(){

    int n, a;
    std::cout << "Enter the size of the array: "; 
    std::cin >> n;

    int* data = new int[n];

    std::cout << "Enter " << n << " numbers: " << std::endl;

    for(int i = 0; i < n; i++){
        std::cin >> a;
        data[i] = a; 
    }

    std::cout << "Your array is : ";

    for(int i = 0; i < n; i++){
        std::cout << data[i] << " ";
    }
    
    std::cout << std::endl;

}
