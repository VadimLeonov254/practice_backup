#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;

bool done = false;
int worker_count = 0;

void work() {
    for (int step = 1; step <= 3; ++step) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Worker finished step " << step << '\n';

        std::unique_lock<std::mutex> lock(mtx);
        worker_count++;

        if (worker_count == 4) {
            std::cout << "All workers have reached the barrier!" << '\n';
            worker_count = 0;
            cv.notify_all();
        } else {
            cv.wait(lock, []{
                return worker_count == 0; 
            });
        }
    }
}

int main() {
    std::thread worker1(work);
    std::thread worker2(work);
    std::thread worker3(work);
    std::thread worker4(work);

    worker1.join();
    worker2.join();
    worker3.join();
    worker4.join();

    std::cout << "All work done!\n";
}
