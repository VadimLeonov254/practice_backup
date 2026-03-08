#include<iostream>
#include<thread>
#include<mutex>
#include<queue>

std::mutex mtx;
std::queue<int> tasks;
int currnum = 1;

int main(){
    
    std::thread worker1([](){
        while(tasks.size() < 100){
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(currnum);
            currnum++;
            std::cout << "Worker 1 completed the task" << '\n';
        }
    });

     std::thread worker2([](){
        while(tasks.size() < 100){
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(currnum);
            currnum++;
            std::cout << "Worker 2 completed the task" << '\n';
        }
    });   

    std::thread worker3([](){
        while(tasks.size() < 100){
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(currnum);
            currnum++;
            std::cout << "Worker 3 completed the task" << '\n';
        }
    });
    
    std::thread worker4([](){
        while(tasks.size() < 100){
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(currnum);
            currnum++;
            std::cout << "Worker 4 completed the task" << '\n';
        }
    });
     
    worker1.join();
    worker2.join();
    worker3.join();
    worker4.join();

}
