#include<iostream>
#include<thread>
#include<atomic>
#include<condition_variable>
#include<queue>

std::deque<int> tasks;
std::mutex mtx;
std::condition_variable cv;
std::atomic<int> i{1};

bool done = false;

void work(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{
            return !tasks.empty() || done;
        });

        if(tasks.empty() && done == true){
            return;
        }
        
        std::cout << tasks.front() << '\n';
        tasks.pop_front();

        cv.notify_all();

    }
}

int main(){
    std::thread producer([](){
        while(done != true){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, []{
                return tasks.size() < 5;
            });
            if(i < 101){
                tasks.push_back(i);
                i++;
            }
            
            if(i == 101){
                done = true;
            }

            cv.notify_all();
        }
    });

    std::thread w1(work);
    std::thread w2(work);

    producer.join();

    w1.join();
        w2.join();
}
