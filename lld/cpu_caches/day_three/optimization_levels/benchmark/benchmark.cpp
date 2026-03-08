#include<iostream>
#include<vector>
#include<chrono>

int main(){
    
    size_t len;
    len = 32 * (1<<20);
    std::vector<int> nums(len);
    
    volatile long long sink;

    for(size_t i = 0; i < len; i++){
        nums[i] = i;
    }

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    
    for(int i = 0; i < 100; i++){
        for(size_t k = 0; k < len; k++){
            sink += nums[k];
        }
    }
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

    std::cout << "Duraion per loop: " << duration.count() / static_cast<float>(len) << '\n';

}
