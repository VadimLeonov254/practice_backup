#ifndef SEMAPHORE_H
#define SEMAPHORE_H
#include<mutex>
#include<atomic>
#include<condition_variable>


class Semaphore{
private:
    std::atomic<int> counter{0};
    std::mutex mtx;
    std::condition_variable cv;

public:
    Semaphore(int count);
    void wait();
    void signal();
};

#endif
