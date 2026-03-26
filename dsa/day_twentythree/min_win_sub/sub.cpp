#include<iostream>
#include<map>

int main(){
    
    std::map<char, int> let;
    
    std::map<char, int> let_u;
    
    int ans = 1000000;
    int ans_k = 0;
    int ans_i = 0;

    std::string word, l;
    std::cout << "Enter the word: ";
    std::cin >> word;
    
    std::cout << "Enter the letters: ";
    std::cin >> l;
    
    int req = 0;
    
    int formed = 0;

    for(int i = 0; i < l.size(); i++){
        if(let_u.find(l[i]) == let_u.end()){
            let_u.emplace(l[i], 1);
            req++;
        }else{
            let_u[l[i]]++;
        }
    } 

    for(int i = 0, k = 0; k < word.size(); k++){
        if(let_u.find(word[k]) != let_u.end()){
            if(let.find(word[k]) == let.end()){
                let.emplace(word[k], 1);
            }else if(let.find(word[k]) != let.end()){
                let[word[k]]++;
            }

            if(let[word[k]] == let_u[word[k]]){
                formed++;
            }

        }
        
        while(formed == req){
            if(k-i+1 < ans){
                ans = k-i+1;
                ans_k = k;
                ans_i = i;
            }

            if(let_u.find(word[i]) != let_u.end()){
                if(let[word[i]]-1 < let_u[word[i]]){
                    formed--;
                }
                let[word[i]]--;
            }
            i++;
        }
    }
    for(int i = ans_i; i < ans_k+1; i++){
        std::cout << word[i];
    }
    std::cout << '\n';
}
