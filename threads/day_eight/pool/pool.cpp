#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>

std::mutex mtx;
std::condition_variable cv;
std::vector<int> queue;

bool done = false;

void work(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{
            return !queue.empty() || done;
        });

        if(queue.empty() && done == true){
            return;
        }

        std::cout << queue.size() << '\n';
        queue.pop_back();
        cv.notify_all();

    }
}

int main(){
    
    std::thread producer([](){
        for(int i = 1; i < 101; i++){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, []{
                return queue.empty() || !done;
            });

            queue.push_back(i);

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
