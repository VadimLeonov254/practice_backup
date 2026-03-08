#include<iostream>
#include<vector>
#include<random>
#include<algorithm>

int main(){
    int num, k;
    std::cout << "Enter the length of the array: ";
    std::cin >> num;
    std::vector<int> nums(num);
    
    std::cout << "Enter the number of the window within the array: ";
    std::cin >> k;


    for(int i = 0; i < num; i++){
        nums[i] = rand() % 11;
    }

    std::cout << "Your array:" << '\n';
    for(int numb : nums){
        std::cout << numb << " ";
    }
    std::cout << '\n';
    std::cout << "Maximums within the window of " << k << '\n';
    for(int i = 0; i<num-k; i++){
        std::cout << *std::max_element(nums.begin() + i, nums.begin() + i + k) << " ";
    }
    
    std::cout << '\n';

}
