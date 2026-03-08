#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include "Semaphore.h"


int main(){
    Semaphore semaphore = Semaphore(3);

    std::thread t1([&](){
        semaphore.wait();
        semaphore.signal();
    });

    std::thread t2([&](){
        semaphore.wait();
        semaphore.signal();
    });

    std::thread t3([&](){
        semaphore.wait();
        semaphore.signal();
    });

    std::thread t4([&](){
        semaphore.wait();
        semaphore.signal();
    });

    std::thread t5([&](){
        semaphore.wait();
        semaphore.signal();
    });

    std::thread t6([&](){
        semaphore.wait();
        semaphore.signal();
    });

    std::thread t7([&](){
        semaphore.wait();
        semaphore.signal();
    });
    

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();

}
