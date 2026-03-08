#include<iostream>
#include<string>
#include<algorithm>

int main(){
    
    std::string text;
    std::cout << "Enter your text:" << '\n';
    std::getline(std::cin, text);
    int ind;
    int c = 0;

    std::reverse(text.begin(), text.end());
    
    for(int i = 0, k = 0; i < text.size();){
        if(k < text.size() && text[k] != ' '){
            k++;
        }else{
            std::reverse(text.begin()+i, text.begin()+k);
            k++;
            i = k;
        }
    }

    std::cout << text << '\n';

}
