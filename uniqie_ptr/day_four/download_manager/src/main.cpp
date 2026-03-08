#include<iostream>
#include<memory>

#include "DownloadManager.h"
#include "DownloadState.h"
#include "IdleState.h"
#include "PauseState.h"
#include "FailState.h"
#include "DownloadingState.h"


int main(){
    DownloadManager manager;

    manager.printState();

    manager.pause();
    manager.printState();

    manager.start();
    manager.printState();

    manager.resume();
    manager.printState();

    manager.pause();
    manager.printState();

    manager.resume();
    manager.printState();

    manager.resume();
    manager.printState();

    manager.fail();
    manager.printState();

    manager.pause();
    manager.printState();

    manager.resume();
    manager.printState();

    manager.start();
    manager.printState();

    manager.fail();
    manager.printState();
}
