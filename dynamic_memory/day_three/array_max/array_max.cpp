#include<iostream>


int arrMax(int* ptr, int size){
    int max = 0;
    for(int i = 0; i < size; i++){
        if (ptr[i] > max){
            max = ptr[i];
        }
    }
    return max;
}


int main(){
	
    int size, a;
	
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* data = new int[size];

    std::cout << "Enter " << size << " numbers below:" << std::endl;

    for(int i = 0; i < size; i++){
        std::cin >> a;
        data[i] = a;
    }

    std::cout << "Maximum of your array is following: " << arrMax(data, size) << std::endl;

}
