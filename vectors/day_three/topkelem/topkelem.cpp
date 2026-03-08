#include<iostream>
#include<vector>
#include<algorithm>
#include<random>

int main(){
    
    int len, pos;

    std::cout << "Enter the size of array: ";
    std::cin >> len;
    
    std::vector<int> nums(len);


    for(int i = 0; i < len; i++){
        nums[i] = rand() % 101;
    }
    std::cout << "The array has been created" << '\n';
    
    std::sort(nums.begin(), nums.end());

    std::cout << "Enter how many best positions you want to see: ";
    std::cin >> pos;

    for(int i = 0; i < pos; i++){
        std::cout << nums[i] << " ";
    }

    std::cout << '\n';

}
