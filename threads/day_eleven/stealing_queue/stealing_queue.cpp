#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<queue>
#include<random>

std::mutex mtx1;
std::mutex mtx2;
std::mutex mtx3;


std::deque<int> tasks1;
std::deque<int> tasks2;
std::deque<int> tasks3;

std::atomic<int> done{0};

void work1(){
    for(int i = 1; i < 51; i++){
        std::lock_guard<std::mutex> lock(mtx1);
        tasks1.push_back(i);
    }
    while(done < 350){

        bool done_yet = false;
        
        {
            std::lock_guard<std::mutex> lock(mtx1);
            if(!tasks1.empty() && done_yet == false){
                std::cout << tasks1.front() << '\n';
                tasks1.pop_front();
                done++;
                done_yet = true;
 
            }
        }

        {
            std::lock_guard<std::mutex> lock(mtx2);
            if(!tasks2.empty() && done_yet == false){
                std::cout << "Task 2 stolen by thread 1: " << tasks2.front() << '\n';
                tasks2.pop_front();
                done++;
                done_yet = true;
            }
        }
        {
            std::lock_guard<std::mutex> lock(mtx3);
            if(done_yet == false && !tasks3.empty()){
                std::cout << "Task 3 stolen by thread 1:" << tasks3.front() << '\n';
                tasks3.pop_front();
                done++;
            }
        }

    }
}

void work2(){
    for(int i = 1; i < 101; i++){
        std::lock_guard<std::mutex> lock(mtx2);
        tasks2.push_back(i);
    }
    while(done < 350){

        bool done_yet = false;
        
        {
            std::lock_guard<std::mutex> lock(mtx1);
            if(!tasks1.empty() && done_yet == false){
                std::cout << "Task 1 stolen by thrwead 2: " << tasks1.front() << '\n';
                tasks1.pop_front();
                done++;
                done_yet = true;
 
            }
        }

        {
            std::lock_guard<std::mutex> lock(mtx2);
            if(!tasks2.empty() && done_yet == false){
                std::cout << tasks2.front() << '\n';
                tasks2.pop_front();
                done++;
                done_yet = true;
            }
        }
        {
            std::lock_guard<std::mutex> lock(mtx3);
            if(done_yet == false && !tasks3.empty()){
                std::cout << "Task 3 stolen by thread 2: " << tasks3.front() << '\n';
                tasks3.pop_front();
                done++;
            }
        }

    }
}   

void work3(){
    for(int i = 1; i < 201; i++){
        std::lock_guard<std::mutex> lock(mtx3);
        tasks3.push_back(i);
    }
    while(done < 350){

        bool done_yet = false;
        
        {
            std::lock_guard<std::mutex> lock(mtx1);
            if(!tasks1.empty() && done_yet == false){
                std::cout << "Task 1 stolen by thread 3: " << tasks1.front() << '\n';
                tasks1.pop_front();
                done++;
                done_yet = true;
 
            }
        }

        {
            std::lock_guard<std::mutex> lock(mtx2);
            if(!tasks2.empty() && done_yet == false){
                std::cout << "Task 2 stolen by thread 3: " << tasks2.front() << '\n';
                tasks2.pop_front();
                done++;
                done_yet = true;
            }
        }
        {
            std::lock_guard<std::mutex> lock(mtx3);
            if(done_yet == false && !tasks3.empty()){
                std::cout << tasks3.front() << '\n';
                tasks3.pop_front();
                done++;
            }
        }

    }
}

int main(){
    
    std::thread worker1(work1);
    std::thread worker2(work2);
    std::thread worker3(work3);

    worker1.join();
    worker2.join();
    worker3.join();
}
