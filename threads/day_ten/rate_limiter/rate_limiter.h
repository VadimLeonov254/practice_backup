#ifndef RATE_LIMITER_H
#define RATE_LIMITER_H
#include<iostream>
#include<condition_variable>
#include<deque>
#include<chrono>
#include<mutex>


class RateLimiter{
private:
    int maxOpsPerSecond;
    std::mutex mtx;
    std::condition_variable cv;
    
    std::deque<std::chrono::steady_clock::time_point> ops;

public:
    RateLimiter(int maxOpsPerSecond);

    void tryAcquire();

};

#endif
