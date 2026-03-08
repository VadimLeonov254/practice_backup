#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

int main(){

    std::map<std::string, int> words;
    
    std::vector<std::string> temps;
    std::vector<std::vector<std::string>> ans;

    int len;
    std::string w;
    std::cout << "Enter the length of the vector: ";
    std::cin >> len;

    std::vector<std::string> nums(len);
    std::vector<std::string> ints(len);
    std::cout << "Enter " << len << " words below: " << '\n';
    
    for(int i = 0; i < len; i++){
        std::cin >> w;
        nums[i] = w;
    }

    for(int i = 0; i < ints.size(); i++){
        ints[i] = nums[i];
    }

    for(int i = 0; i < ints.size(); i++){
        std::sort(ints[i].begin(), ints[i].end());
        if(words.find(ints[i]) == words.end()){
            words.emplace(ints[i], 1); 
        }else{
            words[ints[i]]++;
        }
    }

    for(int i = 0; i < ints.size(); i++){
        if(words[ints[i]] != 0){
            for(int k = 0; k < ints.size(); k++){
                if(ints[i] == ints[k]){
                    temps.push_back(nums[k]);
                }   
            }
            words[ints[i]] = 0;
            ans.push_back(temps);
            temps.clear();
        }
    }
    std::cout << "Group Anagrams:" << '\n'; 
    for(int i = 0; i < ans.size(); i++){
        for(int k = 0; k < ans[i].size(); k++){
            std::cout << ans[i][k] << " "; 
        }
        std::cout << '\n';
    } 

}
