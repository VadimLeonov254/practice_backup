#include<iostream>
#include<vector>
#include<random>

int main(){

    std::vector<int> nums(100);
    
    std::vector<int> nums1;

    for(int i = 0; i < 100; i++){
        nums[i] = rand() % 101;
    }

    for(int number : nums){
        std::cout << number << " ";
    }
    
    std::cout << '\n';
    
    for(int number : nums){
        if(number < 50){
            nums1.push_back(number);
        }
    }
    for(int number : nums1){
        std::cout << number << " ";
    }
}
