#include<iostream>
#include<memory>
#include<vector>

int main(){
    
    int a;
    std::vector<int> nums;
    
    std::cout << "Enter numbers (type 0 to finish entering)" << '\n';
    
    while (a!=0){
        std::cin >> a;
        if(a != 0){
            nums.push_back(a);
        }
    }

    std::cout << "Your array is: " << '\n';
    for(int i = 0; i < nums.size(); i++){
        std::cout << nums[i] << " ";
    }
    
    std::cout << "Your array without without numbers divisible by 3: " << '\n';

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] % 3 == 0){
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    std::cout << "Your array is: " << '\n';
    for(int i = 0; i < nums.size(); i++){
        std::cout << nums[i] << " ";
    }
    std::cout << '\n';
 
}
