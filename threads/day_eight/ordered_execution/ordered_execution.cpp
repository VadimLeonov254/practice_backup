#include<iostream>
#include<thread>
#include<atomic>
#include<condition_variable>

std::mutex mtx;
std::condition_variable cv;


bool doneA = true;
bool doneB = false;
bool doneC = false;


int main(){
    std::thread A([](){
        for(int i = 0; i < 100; i++){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, []{
                return !doneB && !doneC;
            });

            std::cout << "A" << '\n';
            doneA = false;
            doneB = true;
            doneC = false;

            cv.notify_all();
        }
    });

    std::thread B([](){
        for(int i = 0; i < 100; i++){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, []{
                return !doneA && !doneC;
            });

            std::cout << "B" << '\n';
            doneA = false;
            doneB = false;
            doneC = true;
            cv.notify_all();
        }
    });

    std::thread C([](){
        for(int i = 0; i < 100; i++){
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, []{
                return !doneA && !doneB;
            });

            std::cout << "C" << '\n';
            doneA = true;
            doneB = false;
            doneC = false;
            cv.notify_all();

        }
    });

    A.join();
    B.join();
    C.join();
}
