#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>

std::queue<int> tasks;
std::condition_variable cv;
std::mutex mtx;

bool done = false;

void work(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{
            return !tasks.empty() || done;
        });

        if(tasks.empty() && done){
            return;
        }

        std::cout << tasks.front() << '\n';
        tasks.pop();
    }
}



int main(){

    std::thread producer([](){
        for(int i = 1; i < 101; i++){
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(i);
            cv.notify_one();
        }
        {
            std::lock_guard<std::mutex> lock(mtx);
            done = true;
        }
        cv.notify_all();
    });

    std::thread worker1(work);
    std::thread worker2(work);
    std::thread worker3(work);
    std::thread worker4(work);

    producer.join();

    worker1.join();
    worker2.join();
    worker3.join();
    worker4.join();

}
