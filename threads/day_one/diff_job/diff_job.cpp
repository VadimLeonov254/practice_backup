#include<iostream>
#include<thread>
#include<vector>

void work_num(){
    for(int i = 1; i < 6; i++){
        std::cout << i << '\n';
    }
}

void work_letter(){
    std::vector<std::string> letters {"A", "B", "C", "D", "E"};
    for(int i = 0; i < 5; i++){
        std::cout << letters[i] << '\n';
    }
}

int main(){

    std::thread t1(work_num);
    std::thread t2(work_letter);

    t1.join();
    t2.join();

    std::cout << "Main thread is done" << '\n';

}
