#include<iostream>
#include<vector>
#include<chrono>
#include<cmath>

int main(){
    std::cout << "Enter the stride length: ";
    int stride;
    std::cin >> stride;

    int* nums = new int[256 * (1<<20)];
    char* charPtr = reinterpret_cast<char*>(nums);
    
    
    for(size_t i = 0; i < 256*(1<<20); i++){
        nums[i] = i; 
    }
    
    std::cout << "Filled" << '\n';

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    for(size_t i = 0; i < 256*(1<<20); i+=stride){
        if(i < 256*(1<<20)){
            int* intPtr = reinterpret_cast<int*>(charPtr + i);
            *intPtr *= 2;
        }
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

    std::cout << "Duration: " << duration.count()/(256*std::pow(2,20)) << '\n';
    
    delete[] nums;

}
