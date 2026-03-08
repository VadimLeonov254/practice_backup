#include<iostream>
#include<map>

int main(){
    
    int len = 0;
    int ans = 0;
    std::map<char, int> let;
    std::string word;
    std::cout << "Enter the word: ";
    std::cin >> word;
    
    for(int i = 0, k = 0; k < word.size();){
        if(let.find(word[k]) == let.end()){
            let.emplace(word[k], 1);
            len += 1;
            k++;
        }else{
            let.erase(word[i]);
            i++;
            len--;
        }

        if(len > ans){
            ans = len;
        }

    }
    
    std::cout << ans << '\n';

}
