#include<iostream>
#include<map>

int main(){
    
    std::map<char, int> let;

    int n;
    int ans = 0;
    int dist = 0;

    std::string word;
    std::cout << "Enter the word: ";
    std::cin >> word;
    
    std::cout << "Enter the maximum number of distinct characters: ";
    std::cin >> n;
    
    for(int i = 0, k = 0; k < word.size(); k++){
        if(let.find(word[k]) == let.end()){
            let.emplace(word[k], 1);
            dist++;
        }else{
            let[word[k]]++;
        }
     
        while(dist > n){
            if(let[word[i]] == 1){
                dist--;
            }
            let[word[i]]--;
            i++;
        }
        
        if(dist <= n && k-i+1 > ans){
            ans = k-i+1;
        }
    }
    
    std::cout << ans << '\n';

}
