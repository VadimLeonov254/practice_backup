#include<iostream>
#include<memory>
#include "FailState.h"
#include "DownloadingState.h"
#include "DownloadManager.h"
#include "DownloadState.h"

void FailState::start(DownloadManager& manager){
    std::cout << "Program failed, reloading" << std::endl;
    std::cout << std::endl;
    manager.setState(std::make_unique<DownloadingState>());
}


void FailState::pause(DownloadManager& manager){
    std::cout << "Program failed, reloading" << std::endl;
    std::cout << std::endl;
    manager.setState(std::make_unique<DownloadingState>());
}

void FailState::resume(DownloadManager& manager){
    std::cout << "Program failed, reloading" << std::endl;
        std::cout << std::endl;
    manager.setState(std::make_unique<DownloadingState>());
}

void FailState::fail(DownloadManager& manager){
    std::cout << "Really?" << std::endl;
    std::cout << std::endl;
}

void FailState::printState(){
    std::cout << "Program has failed" << std::endl;
    std::cout << std::endl;
}

