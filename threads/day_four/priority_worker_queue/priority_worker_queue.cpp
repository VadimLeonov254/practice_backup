#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<atomic>

std::mutex mtx;
std::condition_variable cv;


std::atomic<int> counter{0};

struct Task{
    int id;
    int priority;

    bool operator<(const Task& other) const {
        return priority < other.priority;
    }

};

std::priority_queue<Task> tasks;

void work(){
    while(counter < 3){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{
            return !tasks.empty();
        });    
        
        std::cout << tasks.top().id << '\n';
        tasks.pop();
        counter++;
        cv.notify_all();
    }
}


int main(){
    std::thread producer([](){
        std::unique_lock<std::mutex> lock(mtx);
        Task task1;
        task1.id = 1;
        task1.priority = 5;
        
        Task task2;
        task2.id = 2;
        task2.priority = 10;

        Task task3;
        task3.id = 3;
        task3.priority = 8;

        tasks.push(task1);
        tasks.push(task2);
        tasks.push(task3);
        cv.notify_all();
    });
    
    std::thread worker1(work);
    std::thread worker2(work);
    std::thread worker3(work);
    
    producer.join();
    worker1.join();
    worker2.join();
    worker3.join();

}
