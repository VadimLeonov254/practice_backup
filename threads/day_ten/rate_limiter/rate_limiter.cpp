#include<iostream>
#include "rate_limiter.h"

using namespace std::chrono;

RateLimiter::RateLimiter(int maxOpsPerSecond) : maxOpsPerSecond(maxOpsPerSecond) {}

void RateLimiter::tryAcquire(){
    std::unique_lock<std::mutex> lock(mtx);

    while(true){
        auto now = steady_clock::now();

        while(!ops.empty() && now - ops.front() >= seconds(1)){
            ops.pop_front();
        }
        if((int)ops.size() < maxOpsPerSecond){
            ops.push_back(now);
            cv.notify_all();
            return;
        }

        auto waitTime = ops.front() + seconds(1) - now;
        cv.wait_for(lock, waitTime);

    }
}
