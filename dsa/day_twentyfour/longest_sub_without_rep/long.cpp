#include<iostream>
#include<map>

int main(){
    
    std::map<char, int> let;
    std::string word;
    
    int ans = 0;

    std::cout << "Enter the word: ";
    std::cin >> word;
    
    for(int i = 0, k = 0; k < word.size(); k++){
        if(let.find(word[k]) == let.end()){
            let.emplace(word[k], 1);
        }else{
            let[word[k]]++;
        }

        while(let[word[k]] > 1){
            let[word[i]]--;
            i++;
        }
        
        if(k-i+1 > ans){
            ans = k-i+1;
        }

    } 
    
    std::cout << ans << '\n';

}
