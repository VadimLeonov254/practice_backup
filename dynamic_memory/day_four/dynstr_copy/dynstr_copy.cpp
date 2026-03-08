#include<iostream>

char* wCopy(const char* data){
    int l = 0;
    char* dat = new char(*data);

    while(data[l]){
        l++;
    }

    for(int i = 1; i < l; i++){
        dat[i] = data[i];
    }

    return dat;
}


int main(){

    std::string word;
    
    std::cout << "Enter the word below" << std::endl;

    std::cin >> word;
    

    const char* data = &word[0];
    
    const char* star = wCopy(data);
    std::cout << "Your word has been copied" << std::endl << star << std::endl;
         
   
}
