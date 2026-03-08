#include<iostream>
#include<thread>
#include<mutex>
#include<vector>

std::vector<int> nums;
std::mutex mtx;

int main(){
    std::thread t1([](){
        for(int i = 1; i < 6; i++){
            std::lock_guard<std::mutex> lock(mtx);
            nums.push_back(i);
        }
    });
    std::thread t2([](){
        for(int i = 6; i < 11; i++){
            std::lock_guard<std::mutex> lock(mtx);
            nums.push_back(i);
        }
    });

    t1.join();
    t2.join();

    for(int i = 0; i < nums.size(); i++){
        std::cout << nums[i] << " ";
    }

    std::cout << '\n';

}
