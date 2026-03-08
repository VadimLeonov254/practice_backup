#include<iostream>
#include<vector>
#include<chrono>
#include<cmath>

int main(){
    int len, num;
    std::cout << "Enter the length of the vector: ";
    std::cin >> len;
    std::vector<int>nums(len);
    std::vector<int>nums_long(256*(1<<20));
    std::cout << "Enter the elements of the vector: " << '\n'; 
    for(int i = 0; i < len; i++){
        std::cin >> num;
        nums[i] = num;
    }

    for(int i = 0; i < 256*(1>>20); i++){
        nums_long[i] = i;
    }
    
    std::chrono::steady_clock::time_point start_reg = std::chrono::steady_clock::now();
    for(int i = 0; i < len; i++){
        nums[i] += 1;
    }
    std::chrono::steady_clock::time_point end_reg = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration_reg = std::chrono::duration_cast<std::chrono::nanoseconds>(end_reg - start_reg);
    std::cout << "Regular vector: " << duration_reg.count() / std::pow(len,1) << '\n';

    std::chrono::steady_clock::time_point start_long = std::chrono::steady_clock::now();
    for(int i = 0; i < (256*(1<<20)); i++){
        nums_long[i] += 1;
    }
    std::chrono::steady_clock::time_point end_long = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration_long = std::chrono::duration_cast<std::chrono::nanoseconds>(end_long-start_long);
    std::cout << "Long vector: " << duration_long.count() / (256 * std::pow(2,20)) << '\n';


}
