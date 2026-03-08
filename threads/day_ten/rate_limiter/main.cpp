#include<iostream>
#include<thread>
#include "rate_limiter.h"

void work(RateLimiter& limiter, int id){
    for(int i = 1; i < 101; i++){
        limiter.tryAcquire();
        std::cout << "Id: " << id << '\n';

    }
}


int main(){
    
    int n;
    std::cout << "How many operations you want to execute in a second?" << '\n';
    std::cin >> n;

    RateLimiter limiter(n);

    std::thread t1(work, std::ref(limiter), 1);
    std::thread t2(work, std::ref(limiter), 2);

    t1.join();
    t2.join();
}
