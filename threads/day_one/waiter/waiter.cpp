#include<iostream>
#include<thread>
#include<chrono>

void waiter(){
    std::cout << "Thread starting" << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread finished" << '\n';
}

int main(){
    std::cout << "Waiting..." << '\n';

    std::thread t1(waiter);
    t1.join();

    std::cout << "Done" << '\n';

}
