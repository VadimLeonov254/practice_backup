#include<iostream>

int countOccur(int* dat, int num){
    int c = 0;
    int l = 0;

    while(dat[l]){
        l++;
    }

    for(int i = 0; i < l; i++){
        
        if(dat[i] == num){
            c++;
        }

    }
    return c;

}

int main(){
    
    int len, a, num;
    std::cout << "Enter the length of array: ";
    std::cin >> len;
    std::cout << "Enter " << len << " numbers below" << std::endl;

    int* data = new int[len]; 

    for(int i = 0; i < len; i++){
        std::cin >> a;
        data[i] = a;
    }

    std::cout << "Enter number: ";
    std::cin >> num;

    std::cout << num << " occurs " << countOccur(data, num) << " times" << std::endl;

}
