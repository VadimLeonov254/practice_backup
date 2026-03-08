#include<iostream>
#include "RWLock.h"

void RWLock::lock_read(){
    read_locked = true;
}

void RWLock::unlock_read(){
    read_locked = false;
}

void RWLock::lock_write(){
    write_locked = true;
}

void RWLock::unlock_write(){
    if(read_locked == true){
        std::cout << "Unable to write at the moment, somebody is reading" << '\n';
        waiting_writers++;
    }else if(write_locked == false){
        std::cout << "Already unlocked to write" << '\n';   
    }else{
        write_locked = false;
    }
}


