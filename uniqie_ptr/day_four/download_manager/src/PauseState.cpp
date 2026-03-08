#include<iostream>
#include<memory>
#include "PauseState.h"
#include "DownloadManager.h"
#include "FailState.h"
#include "DownloadingState.h"

void PauseState::start(DownloadManager& manager){
    std::cout << "Downloading has already started" << std::endl;
    std::cout << std::endl;
}

void PauseState::pause(DownloadManager& manager){
    std::cout << "Already paused" << std::endl;
    std::cout << std::endl;
}

void PauseState::resume(DownloadManager& manager){
    manager.setState(std::make_unique<DownloadingState>());
}

void PauseState::fail(DownloadManager& manager){
    manager.setState(std::make_unique<FailState>());
}

void PauseState::printState(){
    std::cout << "Paused" << std::endl;
    std::cout << std::endl;
}
