#include<iostream>
#include<thread>
#include<atomic>
#include<chrono>

std::atomic<bool> flag(false);



int main(){

    std::thread A([](){
        while(flag == false){
            std::cout << "Still false" << '\n';
        }
    });

    std::thread B([](){
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        flag = true;
        std::cout << "Flag is true now!" << '\n';
    });

    A.join();
    B.join();


}
