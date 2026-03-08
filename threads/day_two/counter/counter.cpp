#include<iostream>
#include<thread>
#include<atomic>

std::atomic<int> count(0);

void increment(){
    for(int i = 0; i < 200000; i++){
        count++;
    }
}

int main(){

    std::thread t1(increment);
    std::thread t2(increment);
    std::thread t3(increment);
    std::thread t4(increment);
    std::thread t5(increment);
    std::thread t6(increment);
    std::thread t7(increment);
    std::thread t8(increment);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    
    
    std::cout << count << '\n';

}
