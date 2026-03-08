#include<iostream>
#include<map>
#include<string>


int main(){
    std::string s, t;
    bool ans;
    std::cout << "Enter the first word: ";
    std::cin >> s;
    
    std::cout << "Enter the second word: ";
    std::cin >> t;

    std::map<char, int> letters;
    std::map<char, int> lettert;

    for(auto i : s){
        if(letters.find(i) != letters.end()){
            letters[i]++;
        }else{
            letters.emplace(i, 1);
        }
    }

    for(auto i : s){
        if(lettert.find(i) != lettert.end()){
            lettert[i]++;
        }else{
            lettert.emplace(i, 1);
        }
    }

    for(auto i : t){
        if(letters[i] != lettert[i] || s.length() != t.length()){
            std::cout << "Not an anagram" << '\n';
            return false;
        }
    }
    std::cout << "Is an anagram" << '\n';
    return true;
}
