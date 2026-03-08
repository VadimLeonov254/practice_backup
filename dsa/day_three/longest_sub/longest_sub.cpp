#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

int main(){
    
    std::vector<int> nums;
    std::map<std::string, int> letters;
    std::string word;
    std::cout << "Enter the word: ";
    std::cin >> word;
    int maxi = 0;
    int len = 0;

    for(int l = 0, r = 0; l < word.size();){
        if(word[l] == word[r]){
            len++;
            r++;
        }else if(word[l] != word[r]){
            if(len > 0){
                nums.push_back(len);
            }
            l = r;
            len = 0;
        }
    }
    
   maxi = *std::max_element(nums.begin(), nums.end());

   std::cout << maxi << '\n';

}
