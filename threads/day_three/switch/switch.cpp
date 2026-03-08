#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>


std::mutex mtx;
std::condition_variable cv;

bool turnA = false;



int main(){
    std::thread A([](){
        for(int i = 1; i < 11; i++){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{
                return !turnA;
            });    
            std::cout << "A" << i << '\n';
            turnA = true;
            cv.notify_one();
        }
    });

    std::thread B([](){
        for(int i = 1; i < 11; i++){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{
                return turnA;
            });
            std::cout << "B" << i << '\n';
            turnA = false;
            cv.notify_one();
        }
    });

    A.join();
    B.join();

}
