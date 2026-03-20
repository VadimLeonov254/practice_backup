#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

int main(){
    
    int num;
    std::string word;
        
    std::map<std::string, std::vector<std::string>> ans;

    std::cout << "Enter the length of vector: ";
    std::cin >> num;
    
    std::vector<std::string> nums(num);
    
    std::cout << "Enter " << num << " words: " << '\n';

    for(int i = 0; i < num; i++){
        std::cin >> word;
        nums[i] = word;

        std::cout << nums[i] << " ";
    }
    
    std::cout << '\n' << '\n'; 
    
    for(int i = 0; i < num; i++){
        
        std::string k = nums[i];
        std::sort(k.begin(), k.end());

        if(ans.find(k) == ans.end()){
            ans[k] = {nums[i]};
        }else{
            ans[k].push_back(nums[i]);
        }
        

    } 
    
    for(const auto& pair : ans){
        for(int i = 0; i < pair.second.size(); i++){
            std::cout << pair.second[i] << " ";
        }
        std::cout << '\n';
    }

}
