#include<iostream>
#include<thread>
#include<mutex>

int num = 1;

std::mutex mtx;

void print(){
    for(int i = 0; i < 5; i++){
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Thread " << num << " says hi!" << '\n';
        }
    }
    num++;
}

int main(){
    std::thread t1(print);
    std::thread t2(print);
    std::thread t3(print);

    t1.join();
    t2.join();
    t3.join();

}
