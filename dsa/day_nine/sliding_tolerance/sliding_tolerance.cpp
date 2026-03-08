#include<iostream>
#include<vector>
#include<map>

int main(){
    
    std::map<char, int> nums;
    

    int num, window;
    int max_freq = 0;
    std::string word;
    std::cout << "Enter the word: ";
    std::cin >> word;
    
    std::cout << "Enter max amount of replacements: ";
    std::cin >> num; 
    
    for(int i = 0, k = 0; k < word.size();){
        if(nums.find(word[k]) == nums.end()){
            nums.emplace(word[k], 1);
        }else{
            nums[word[k]]++;
        }
        if(nums[word[k]] > max_freq){
            max_freq = nums[word[k]];
        }       
        
        k++;
        window = k - i;
                    
        while(window - max_freq > num){
            window = k - i;
            nums[word[i]]--;
            i++;
        }

    }
    
    std::cout << window << '\n';


}
