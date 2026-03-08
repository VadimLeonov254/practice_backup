#include<iostream>

int* returnMax(int &a, int &b, int &c){
    if(a > b && a > c){
        return &a;
    }else if(b > a && b > c){
        return &b;
    }else if(c > a && c > b){
        return &c;
    }
}



int main(){

    int x, y, z;
    std::cin >> x >> y >> z;
    int *max = returnMax(x, y, z);

    std::cout << *max << std::endl;
    
    std::cout << &x << " " << x << std::endl;
    std::cout << &y << " " << y << std::endl;
    std::cout << &z << " " << z << std::endl; 


}
