#include<iostream>
#include<thread>
#include "library.h"

void library::student_enter(){
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{
        return !is_researcher_inside && researchers_waiting == 0;
    });
    active_students++;
}

void library::student_leaves(){
    std::unique_lock<std::mutex> lock(mtx);
    active_students--;
    if(active_students == 0 && researchers_waiting > 0){
        cv.notify_one();
    }
}

void library::researcher_enter(){
    std::unique_lock<std::mutex> lock(mtx);
    researchers_waiting++;
    cv.wait(lock, []{
        return active_students == 0 && !is_researcher_inside;
    });
    researchers_waiting--;
    is_researcher_inside = true;
    cv.notify_all();
}

void library::researcher_leave(){
    std::unique_lock<std::mutex> lock(mtx);
    is_researcher_inside = false;
    if(researchers_waiting > 0){
        cv.notify_one();
    }else{
        cv.notify_all();
    }
}
