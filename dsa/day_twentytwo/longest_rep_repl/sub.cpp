#include<iostream>
#include<vector>
#include<random>
#include<map>

int main(){
    
    std::map<char, int> let;

    std::string word;
    std::cout << "Enter the word: ";
    std::cin >> word;

    int num;
    
    int ans = 0;
    
    int most = 0;

    std::cout << "Enter the max of the characters you want to replace: ";
    std::cin >> num;
    
    
    for(int i = 0, k = 0; k < word.size(); k++){
        if(let.find(word[k]) == let.end()){
            let.emplace(word[k], 1);
        }else{
            let[word[k]]++;
        }
        
        if(let[word[k]] > most){
            most = let[word[k]];
            std::cout << "most" << most << '\n';
        } 
                
        if(k-i+1 - most <= num){
            if(k-i+1 > ans){
                ans = k-i+1;
            }
        } 
        
        while(k-i+1 - most > num){
            if(i > word.size()) break;
            let[word[i]]--;
            i++;
        }


    }
    
    std::cout << ans << '\n';

}
