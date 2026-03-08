#include<iostream>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>


std::queue<int> queue;
std::mutex mtx;
std::condition_variable cv;


int main(){
    
    std::thread producer([](){
        for(int i = 0; i < 21; i++){
            std::lock_guard<std::mutex> lock(mtx);
            queue.push(i);
            cv.notify_all();
        }
    });
    
    std::thread consumer([](){
        int count = 21;
        while(count > 0){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, []{
                return !queue.empty();
            });
            std::cout << queue.front() << '\n';
            queue.pop();
            count --;
         }
    });

    producer.join();
    consumer.join();

}
