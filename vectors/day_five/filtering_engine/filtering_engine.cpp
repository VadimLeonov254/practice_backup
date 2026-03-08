#include<iostream>
#include<vector>
#include<algorithm>


int main(){
    int num, el, count;
    std::cout << "Enter the length of the array: ";
    std::cin >> num;
    std::vector<int> nums;
    
    std::cout << "Enter " << num << " numbers" << '\n';

    for(int i = 0; i < num; i++){
        std::cin >> el;
        nums.push_back(el);
    }

    for(int i = 0; i < num; i++){
        std::cout << nums[i] << " "; 
    }

    std::cout << '\n';
    
    for(int i = 0; i < num/2; i++){
        int temp = nums[i];
        nums[i] = nums[num-i-1];
        nums[num-i-1] = temp;
    }

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 100 || std::count(nums.begin(), nums.end(), nums[i]) > 1){
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    
    std::cout << "Your filtered array:" << '\n';
    for(int i = 0; i < nums.size()/2; i++){
        int temp = nums[i];
        nums[i] = nums[nums.size()-i-1];
        nums[nums.size()-i-1] = temp;
    }

    for(int i = 0; i < nums.size(); i++){
        std::cout << nums[i] << " "; 
    }
    
    std::cout << '\n';

}
