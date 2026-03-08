#include<iostream>
#include<vector>

int main(){

    int len;
    int num;
    std::cout << "Enter the length of an array: ";
    std::cin >> len;
    std::vector<int> nums(len);
    std::vector<int> ans(len);

    for(int i = 0; i < len; i++){
        std::cin >> num;
        nums[i] = num;
    }

    num = 0;

    for(int i = 0; i < len; i++){
        if(nums[i] != 0){
            num++;
        }
    }
       
    for(int i = 0, k = nums.size()-1; i < num;){
        if(nums[i] == 0){
            nums.erase(nums.begin() + i);
            nums[k] = 0;
        }else{
            i++;
        }
    } 
    
    for(int i = 0; i < ans.size(); i++){
        ans[i] = nums[i];
    }

    std::cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i] << " ";
    }
    std::cout << '\n';
}
