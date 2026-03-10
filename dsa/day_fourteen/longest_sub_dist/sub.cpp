#include<iostream>
#include<map>

int main(){
    
    std::map<char, int> let;

    int num;
    int ans = 0;
    int count = 0;

    std::string word;
    std::cout << "Enter the word: ";
    std::cin >> word;
    
    std::cout<< "Enter the max of the distinct characters that can occur: ";
    std::cin >> num;
     
    for(int i = 0, k = 0; k < word.size();){
        

        if(let.find(word[k]) == let.end()){
            let.emplace(word[k], 1);
            count++;
        }else{
            let[word[k]]++;
        }
        
        

        if(count <= num){
            if(k-i+1 > ans){
                ans = k-i+1;
            }
            k++;
        }else{
            if(let[word[i]]-1 == 0){
                count--;
            }
            let[word[i]]--;
            i++;
        }
        
        

    }
    std::cout << ans << '\n';       

}

