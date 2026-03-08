#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H
#include "DownloadState.h"
#include<memory>

class DownloadManager{

private:
    std::unique_ptr<DownloadState> state;

public:

    DownloadManager();
    void start();
    void pause();
    void resume();
    void fail();
    void printState();

    void setState(std::unique_ptr<DownloadState> newstate){
        state = std::move(newstate);
    }


};

#endif
