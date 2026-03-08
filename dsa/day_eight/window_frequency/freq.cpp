#include<iostream>
#include<vector>
#include<map>
#include<string>

int main(){

    bool done = false;
    
    int check = 0;

    std::map<char, int> let_word;
    std::map<char, int> let_perm;

    std::string word;
    std::string perm;

    std::cout << "Enter a word: ";
    std::cin >> word;
    
    std::cout << "Enter a permutation: ";
    std::cin >> perm;

    for(int i = 0; i < perm.size(); i++){
        if(let_perm.find(perm[i]) == let_perm.end()){
            let_perm.emplace(perm[i], 1);
        }else{
            let_perm[perm[i]]++;
        }
    }

    for(int i = 0; i < perm.size(); i++){
        if(let_word.find(word[i]) == let_word.end()){
            let_word.emplace(word[i], 1);
            if(let_perm.find(word[i]) != let_perm.end()){
                check++;
            }
        }else{
            let_word[word[i]]++;
            
        }
        if(let_perm.find(word[i]) != let_perm.end()){
            check++;
        }       
    }
    
    if(check == perm.size()){
        done = true;     
    }
    check = 1; 
    if(done == false){
        for(int i = 1, k = perm.size(); k < word.size();){
            if(let_perm.find(word[i]) == let_perm.end() && check > 0){
                check--;
            }
            if(let_word.find(word[i]) == let_word.end()){
                let_word[word[i]]++;
                let_word.erase(word[i-1]);
            }else{
                let_word.emplace(word[i], 1);
                let_word.erase(word[i-1]);
            }
            if(let_perm.find(word[i]) != let_perm.end()){
                check++;
            }
            i++;
            k++;
            if(check == perm.size()){
                done = true;
                break;
            }else{
            }

        }
    }
    
    if(done == true){
        std::cout << "YES!" << '\n';
    }else{
        std::cout << "NO!" << '\n';
    }
}
