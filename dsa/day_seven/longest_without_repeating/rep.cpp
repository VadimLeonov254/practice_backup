#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

int main(){
    
    int sum = 0;
    std::map<char, int> seen;
    std::string word;
    std::cout << "Enter the word: ";
    std::cin >> word;
    std::vector<int> sums;
    

    for(int i = 0, k = 0; k < word.size();){
        if(seen.find(word[k]) == seen.end()){
            seen.emplace(word[k], 1);
            sum++;
            if(k == word.size()-1){
                sums.push_back(sum);
            }
            k++;
        }else{
            seen.erase(word[i]);
            i++;
            sums.push_back(sum);
            sum = 0;
        }
    }

    std::cout << "Longest substring without repeats: " << *max_element(sums.begin(), sums.end()) << '\n';

}
