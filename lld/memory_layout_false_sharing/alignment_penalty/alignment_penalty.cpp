#include<iostream>
#include<vector>
#include<chrono>
#include<cstdlib>
#include<memory>

struct Test_64{
    int num = 10;
};

struct Test_63{
    char word;
    int num = 10;
};

int main(){
    
    size_t n = 300000000;

    auto test_64 = static_cast<Test_64*>(std::aligned_alloc(64, n * sizeof(Test_64)));

    auto test_63 = new Test_63[n];

    volatile int sink = 0; 
    
    for(size_t i = 0; i < n; i++){
        sink += test_64[i].num;
    }
    
    sink = 0;

    std::chrono::steady_clock::time_point start_64 = std::chrono::steady_clock::now();
    for(size_t i = 0; i < n; i++){
        sink += test_64[i].num;
    }
    std::chrono::steady_clock::time_point end_64 = std::chrono::steady_clock::now();
    
    std::chrono::nanoseconds duration_64 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_64 - start_64);
    
    sink = 0;

    std::chrono::steady_clock::time_point start_63 = std::chrono::steady_clock::now();
    for(size_t i = 0; i < n; i++){
        sink += test_63[i].num;
    }
    std::chrono::steady_clock::time_point end_63 = std::chrono::steady_clock::now();
    
    std::chrono::nanoseconds duration_63 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_63 - start_63);

    std::cout << "Duration of the 64 alignment: " << duration_64.count() / static_cast<double>(n) << '\n';
    std::cout << "Duration of the 63 alignment: " << duration_63.count() / static_cast<double>(n) << '\n';
    
    std::free(test_64);
    delete[] test_63;

}
