#include<iostream>
#include<thread>
#include<atomic>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<random>

std::mutex mtx;
std::condition_variable cv;

struct Task{
    int id;
    int priority;

    bool operator<(const Task& other) const{
        return priority < other.priority;
    };

};

bool done = false;

std::priority_queue<Task> tasks;

void work(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{
            return !tasks.empty() || done == true;
        });
        
        if(tasks.empty() && done){
            return;
        }

        std::cout << tasks.top().id << '\n'; 
        tasks.pop();
        
        cv.notify_all();
    }
}


int main(){
    std::thread producer([](){
        for(int i = 1; i < 101; i++){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, []{
                return tasks.size() < 10;
            });
            Task task;
            task.id = i;
            task.priority = rand() % 1001;
            tasks.push(task);
            cv.notify_all();
        }
        {
            std::lock_guard<std::mutex> lock(mtx);
            done = true;
            cv.notify_all();
        }
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
