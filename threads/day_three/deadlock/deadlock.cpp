#include<iostream>
#include<thread>
#include<mutex>


std::mutex mtxA;
std::mutex mtxB;

int count = 0;

int main(){

    std::thread t1([](){
        for(int i  = 0; i < 10000; i++){
            std::lock_guard<std::mutex> lock(mtxA);
            count++;
        }
        std::lock_guard<std::mutex> lock(mtxB);
    });

    std::thread t2([](){
        for(int i = 0; i < 10000; i++){
            std::lock_guard<std::mutex> lock(mtxB);
            count++;
        }
        std::lock_guard<std::mutex> lock(mtxA);
    });

    t1.join();
    t2.join();
    
    std::cout << count << '\n';

}
