#include<iostream>
#include<vector>
#include<map>

int main(){
    
    
    int num;
    int dist = 0;
    int ans = 0;
    std::string word;

    std::cout << "Enter the word: ";
    std::cin >> word;

    std::map<char, int> let;
    
    
    dist = 0;

    for(int i = 0, k = 0; k < word.size();){


        if(let.find(word[k]) == let.end()){
            let.emplace(word[k], 1);
            dist++;
        }else{
            let[word[k]]++;
        }
        

        k++;
    
        while(dist > 2){
            if(let[word[i]] == 1){
                dist--;
            }
            let[word[i]]--;
            i++;
        }

        if(k-i > ans){
            ans = k-i;
        }

    }

    
    std::cout << ans << '\n';

}
