#ifndef LIBRARY_H
#define LIBRARY_H
#include<mutex>
#include<condition_variable>

class Library{
private:
    int active_students = 0;
    int researchers_waiting = 0;
    bool is_researcher_inside = false;
    std::mutex mtx;
    std::condition_variable cv;
public:
    void student_enter();
    void student_leave();

    void researched_enter();
    void researcher_leave();
};

#endif
