#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>


std::mutex mtx;
std::condition_variable cv;

bool turnA = true;

void outA(std::string letter){
    for(int i = 1 ; i < 11; i++){
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{
                return turnA;
            });
            std::cout << letter << i << '\n';
            turnA = !turnA;
            cv.notify_all();
        }
    }
}

void outB(std::string letter){
    for(int i = 1 ; i < 11; i++){
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{
                return !turnA;
            });
            std::cout << letter << i << '\n';
            turnA = !turnA;
            cv.notify_all();
        }
    }
}

int main(){
    
    std::thread A(outA, "A");
    std::thread B(outB, "B");

    A.join();
    B.join();

}
