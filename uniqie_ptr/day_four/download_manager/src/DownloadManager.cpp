#include<iostream>
#include<memory>
#include "DownloadManager.h"
#include "IdleState.h"
#include "PauseState.h"
#include "DownloadingState.h"
#include "FailState.h" 

DownloadManager::DownloadManager(){
    state = std::make_unique<IdleState>();
}

void DownloadManager::start(){
    state -> start(*this);
}

void DownloadManager::pause(){
    state -> pause(*this);
}

void DownloadManager::resume(){
    state -> resume(*this);
}

void DownloadManager::fail(){
    state -> fail(*this);
}

void DownloadManager::printState(){
    state -> printState();
}
