#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include "RWLock.h"

RWLock rwlock;

void reader(int id) {
    std::cout << "Reader " << id << " wants to read\n";

    rwlock.lock_read();
    std::cout << "Reader " << id << " is reading\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "Reader " << id << " finished reading\n";
    rwlock.unlock_read();
}

void writer(int id) {
    std::cout << "Writer " << id << " wants to write\n";

    rwlock.lock_write();
    std::cout << "Writer " << id << " is writing\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "Writer " << id << " finished writing\n";
    rwlock.unlock_write();
}

int main() {
    std::vector<std::thread> threads;

    threads.emplace_back(reader, 1);
    threads.emplace_back(reader, 2);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    threads.emplace_back(writer, 1);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    threads.emplace_back(reader, 3);

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All threads done!\n";
    return 0;
}
