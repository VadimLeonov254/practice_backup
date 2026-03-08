#include<iostream>
#include<thread>

void work(){
    std::cout << "Hello from thread ID: " << std::this_thread::get_id() << '\n';
}

int main(){
    std::thread t1(work);
    std::thread t2(work);

    t1.join();
    t2.join();

    std::cout << "Main thread done" << '\n';

}
