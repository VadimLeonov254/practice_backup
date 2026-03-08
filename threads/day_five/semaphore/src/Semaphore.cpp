#include<iostream>
#include<mutex>
#include<thread>
#include<atomic>
#include<condition_variable>
#include "Semaphore.h"


Semaphore::Semaphore(int count) : counter(count) {}


void Semaphore::wait(){
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&]{
        return counter > 0;
    });
    std::cout << "Inside the " << std::this_thread::get_id() << " thread" << '\n';
    counter--;

}

void Semaphore::signal(){
    std::lock_guard<std::mutex> lock(mtx);
    counter++;
    cv.notify_one();
}
