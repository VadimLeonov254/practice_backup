#ifndef RWLOCK_H
#define RWLOCK_H
#include<mutex>
#include<condition_variable>


class RWLock{
private:
    int active_readers = 0;
    bool writer_active = false;
    int waiting_writers = 0;

    bool read_locked = false;
    bool write_locked = false;

    std::mutex mtx;
    std::condition_variable;
public:
    void lock_read();
    void unlock_read();
    void lock_write();
    void unlock_write();

    int get_readers();
    bool isWriterActive();
    int get_waitingWriters;

};

#endif
