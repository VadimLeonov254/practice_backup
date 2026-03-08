#include<iostream>
#include<map>

int main(){
    
    std::map<char, int> let;

    int num, win;
    int ans = 0;
    int freq = 0;
    std::string word;
    std::cout << "Enter the word: ";
    std::cin >> word;

    std::cout << "Enter the maximum of characters that can be changed: ";
    std::cin >> num;

    for(int i = 0, k = 0; k < word.size();){
        
        if(let.find(word[k]) == let.end()){
            let.emplace(word[k], 1);
        }else{
            let[word[k]]++;
        }
        
        if(let[word[k]] > freq){
            freq = let[word[k]];
        }
        
       
        while(k-i+1 - freq > num){
            let[word[i]]--;
            i++;
        }

        
        if(k-i+1 > ans){
            ans = k-i+1;
        }

        k++;
    }

    std::cout << ans << '\n';

}
