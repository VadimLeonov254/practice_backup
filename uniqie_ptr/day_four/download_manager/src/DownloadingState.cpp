#include<iostream>
#include<memory>
#include "DownloadingState.h"
#include "DownloadManager.h"
#include "PauseState.h"
#include "FailState.h"

void DownloadingState::start(DownloadManager& manager){
    std::cout << "Already downloading" << std::endl;
    std::cout << std::endl;
}

void DownloadingState::pause(DownloadManager& manager){
    manager.setState(std::make_unique<PauseState>());
}

void DownloadingState::resume(DownloadManager& manager){
    std::cout << "Already downloading" << std::endl;
    std::cout << std::endl;
}

void DownloadingState::fail(DownloadManager& manager){
    manager.setState(std::make_unique<FailState>());
}

void DownloadingState::printState(){
    std::cout << "Downloading" << std::endl;
    std::cout << std::endl;
}
