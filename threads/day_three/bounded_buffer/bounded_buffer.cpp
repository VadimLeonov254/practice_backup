#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>

std::queue<int> tasks;

std::mutex mtx;
std::condition_variable cv;

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
        cv.notify_all(); 
    }
}


int main(){
    std::thread producer([](){
        for(int i = 1; i < 201; i++){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{
                return tasks.size() < 10;
            });
            tasks.push(i);

            if(tasks.size() == 10){
                cv.notify_all();
            }
        }
        {
            std::lock_guard<std::mutex> lock(mtx);
            done = true;
        }
    });

    std::thread worker1 (work);
    std::thread worker2 (work);
    std::thread worker3 (work);
    std::thread worker4 (work);

    producer.join();

    worker1.join();
    worker2.join();
    worker3.join();
    worker4.join();


}
