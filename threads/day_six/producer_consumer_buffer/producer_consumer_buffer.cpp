#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<condition_variable>
#include<vector>


std::mutex mtx;
std::condition_variable cv;

std::vector<int> prod;

std::atomic<bool> done{false};

std::atomic<int> size{0};
std::atomic<int> producer_count{0};
std::atomic<int> global_count{1};

void produce(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{
            return prod.size() < size;
        });
        
        if(global_count >= 1001){
            break;
        }
        
       
        prod.push_back(global_count);
        global_count++;
       
        cv.notify_all();

    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        producer_count++;
        if(producer_count == 4){
            done = true;
            cv.notify_all();
        }
    }

    
}

void consume(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{
            return !prod.empty() || done;
        });

        if(prod.empty() && done){
            return;
        }

        std::cout << prod.back() << '\n';
        prod.pop_back();
        cv.notify_all();
    }
}

int main(){
    int ln;
    std::cout << "Enter the size of the buffer: ";
    std::cin >> ln;

    size = ln;
    std::thread producer1(produce);
    std::thread producer2(produce);
    std::thread producer3(produce);
    std::thread producer4(produce);

    std::thread consumer1(consume);
    std::thread consumer2(consume);
    std::thread consumer3(consume);
    std::thread consumer4(consume);

    

    producer1.join();
    producer2.join();
    producer3.join();
    producer4.join();
    
    consumer1.join();
    consumer2.join();
    consumer3.join();
    consumer4.join();
}
