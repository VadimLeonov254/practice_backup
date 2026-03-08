#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<condition_variable>
#include<queue>
#include<random>

std::mutex mtx;
std::condition_variable cv;
std::atomic<int> counter{1};
std::atomic<int> prod_finished{0};

bool done = false;

struct Task{
    int id;
    int priority;

    bool operator<(const Task& other) const{
        return priority < other.priority;
    }
};

std::priority_queue<Task> tasks;

void produce(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);

        if(counter >= 101){
            prod_finished++;
            if(prod_finished == 3){
                done = true;
                cv.notify_all();
            }
            return;
        }
        
        Task task;
        task.id = counter;
        task.priority = rand() % 1001;
        tasks.push(task);
        counter++;
        cv.notify_all();

    }
    
}

void work(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{
            return !tasks.empty() || done == true;
        });
        
        if(tasks.empty() && done){
            return;
        }

        std::cout << tasks.top().id << ": " << tasks.top().priority << '\n';
        tasks.pop();
        
        cv.notify_all();

    }
}

int main(){

    std::thread producer1(produce);
    std::thread producer2(produce);
    std::thread producer3(produce);

    std::thread worker1(work);
    std::thread worker2(work);
    std::thread worker3(work);

    producer1.join();
    producer2.join();
    producer3.join();

    worker1.join();
    worker2.join();
    worker3.join();

}
