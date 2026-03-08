#include<iostream>
#include<vector>

int main(){
    
    int len;
    std::cout << "Enter the length of the array: ";
    std::cin >> len;

    std::vector<int> nums(len);
    std::vector<int> new_nums;


    for(int i = 0; i < len; i++){
        nums[i] = rand() % 101;
    }

    for(int i = 0; i < len; i++){
        std::cout << nums[i] << " ";
    }
    
    std::cout << '\n';

    for(int i = 0; i < len; i++){
        for(int k = 0; k < len-i-1; k++){
            if(nums[k] > nums[k+1]){
                int temp = nums[k];
                nums[k] = nums[k+1];
                nums[k+1] = temp;
            }
        }
    }
    
    std::cout << "Sorted:" << '\n';

    for(int i = 0; i < len; i++){
        std::cout << nums[i] << " ";
    }
    std::cout << '\n';

    for(int i = 0; i < len-1; i++){
        
        if(nums[i] != nums[i+1]){
            new_nums.push_back(nums[i]);
        }
        
    }
    std::cout << "Array without dulicates" << '\n';
    for(int i = 0; i < new_nums.size(); i++){
        std::cout << new_nums[i] << " ";
    }
    std::cout << '\n';
    
    std::cout << "Number of duplicates found in the original array:" << len - new_nums.size() << '\n';
    
}


