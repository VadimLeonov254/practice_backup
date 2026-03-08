#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<atomic>
#include<chrono>
#include<queue>

std::mutex mtx;
std::condition_variable cv;

std::atomic<int> i{1};
std::deque<int> tasks;
bool done = false;

void submitTask(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{
            return !tasks.empty() || done == true;
        });

        if(tasks.empty() && done){
            return;
        }
        

        std::cout << tasks.front() << '\n';
        tasks.pop_front();
        cv.notify_all();
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void work(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{
            return tasks.size() < 5;
        });
        if(i < 101){
            tasks.push_back(i);
            i++;
        }else{
            done = true;
            return;
        }
        cv.notify_all();
    }
}


int main(){
    std::thread processor(submitTask);
    std::thread worker1(work);
    std::thread worker2(work);

    processor.join();
    worker1.join();
    worker2.join();
}
