#include<iostream>
#include<atomic>
#include<thread>
#include<chrono>

struct Counter{
    std::atomic<long> value = 0;
};

struct alignas(64) PaddedCounter{
    std::atomic<long> value = 0;
    char padding[64 - sizeof(std::atomic<long>)];
};

void run_reg(){
    long n = 100000000;
    Counter counters[2];

    auto start = std::chrono::steady_clock::now();
    std::thread t0([&](){
        for(int i = 0; i < n; i++){
            counters[0].value++;
        }
    });

    std::thread t1([&](){
        for(int i = 0; i < n; i++){
            counters[1].value++;
        }
    });

    t0.join();
    t1.join();
    
    auto end = std::chrono::steady_clock::now();
    
    std::cout << "Regular duration: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << '\n';
    std::cout << "Regular duration per increment: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / static_cast<double>(2*n) << '\n';
}

void run_pad(){
    long n = 100000000;
    PaddedCounter paddedcounters[2];

    auto start = std::chrono::steady_clock::now();
    std::thread t0([&](){
        for(int i = 0; i < n; i++){
            paddedcounters[0].value++;
        }
    });

    std::thread t1([&](){
        for(int i = 0; i < n; i++){
            paddedcounters[1].value++;
        }
    });

    t0.join();
    t1.join();
    
    auto end = std::chrono::steady_clock::now();
    
    std::cout << "Padded duration: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << '\n';
    std::cout << "Padded duration per increment: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / static_cast<double>(2*n) << '\n';


}

int main(){
    
    run_reg();
    run_pad();
    
}
