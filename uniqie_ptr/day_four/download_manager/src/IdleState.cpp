#include<iostream>
#include<memory>
#include "IdleState.h"
#include "DownloadState.h"
#include "DownloadManager.h"
#include "FailState.h"
#include "DownloadingState.h"

void IdleState::start(DownloadManager& manager){
    manager.setState(std::make_unique<DownloadingState>());
}

void IdleState::pause(DownloadManager& manager){
    std::cout << "Nothing to pause!" << std::endl;
    std::cout << std::endl;
}

void IdleState::resume(DownloadManager& manager){
    std::cout << "Nothing to resume" << std::endl;
    std::cout << std::endl;
}

void IdleState::fail(DownloadManager& manager){
    manager.setState(std::make_unique<FailState>());
}

void IdleState::printState(){
    std::cout << "Idling" << std::endl;
    std::cout << std::endl;
}

