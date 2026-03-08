#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<atomic>
#include<chrono>

std::atomic<int> done{0};

struct Fork{
    int id;
    bool is_taken = false;
};

std::deque<Fork> forks;

std::mutex mtx;
std::condition_variable cv;


void frog1(){
    {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "First philospher is thinking" << '\n';
        cv.wait(lock, [&]{
            return forks[0].is_taken == false && forks[4].is_taken == false; 
        });

        forks[0].is_taken = true;
        forks[4].is_taken = true;
        std::cout << "First philospher is eating now!" << '\n';
        cv.notify_all();
    }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(mtx);    
        forks[0].is_taken = false;
        forks[4].is_taken = false;
        
        std::cout << "First philosopher just finished eating!" << '\n';

        done++;
        cv.notify_all();
    }

}

void frog2(){
    {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "Second philospher is thinking" << '\n';
        cv.wait(lock, [&]{
            return forks[0].is_taken == false && forks[1].is_taken == false; 
        });

        forks[0].is_taken = true;
        forks[1].is_taken = true;
        std::cout << "Second philospher is eating now!" << '\n';
        cv.notify_all();
    }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(mtx);    
        forks[0].is_taken = false;
        forks[1].is_taken = false;
        
        std::cout << "Second philosopher just finished eating!" << '\n';

        done++;
        cv.notify_all();
    }

}

void frog3(){
    {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "Third philospher is thinking" << '\n';
        cv.wait(lock, [&]{
            return forks[1].is_taken == false && forks[2].is_taken == false; 
        });

        forks[1].is_taken = true;
        forks[2].is_taken = true;
        std::cout << "Third philospher is eating now!" << '\n';
        cv.notify_all();
    }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    {    
        std::lock_guard<std::mutex> lock(mtx);
        forks[1].is_taken = false;
        forks[2].is_taken = false;
        
        std::cout << "Third philosopher just finished eating!" << '\n';

        done++;
        cv.notify_all();
    }
}

void frog4(){
    {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "Fourth philospher is thinking" << '\n';
        cv.wait(lock, [&]{
            return forks[2].is_taken == false && forks[3].is_taken == false; 
        });

        forks[2].is_taken = true;
        forks[3].is_taken = true;
        std::cout << "Fourth philospher is eating now!" << '\n';
        cv.notify_all();
    }  
        std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(mtx);
        forks[2].is_taken = false;
        forks[3].is_taken = false;
        
        std::cout << "Fourth philosopher just finished eating!" << '\n';

        done++;
        cv.notify_all();
    }
}

void frog5(){
     {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "Fifth philospher is thinking" << '\n';
        cv.wait(lock, [&]{
            return forks[3].is_taken == false && forks[4].is_taken == false; 
        });

        forks[3].is_taken = true;
        forks[4].is_taken = true;
        std::cout << "Fifth philospher is eating now!" << '\n';
    }
        std::this_thread::sleep_for(std::chrono::seconds(1));
       
    {
        std::lock_guard<std::mutex> lock(mtx);   
        forks[3].is_taken = false;
        forks[4].is_taken = false;
        
        std::cout << "Fifth philosopher just finished eating!" << '\n';

        done++;

        cv.notify_all();
    }
}


int main(){
 
    for(int i = 1; i < 6; i++){
        Fork fork;
        fork.id = i;
        forks.push_back(fork);
    }
    std::thread p1(frog1);
    std::thread p2(frog2);
    std::thread p3(frog3);
    std::thread p4(frog4);
    std::thread p5(frog5);

    p1.join();
    p2.join();
    p3.join();
    p4.join();
    p5.join();

}
