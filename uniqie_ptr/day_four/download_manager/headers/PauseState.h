#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "DownloadState.h" 
#include "DownloadManager.h"

class PauseState : public DownloadState{
public:    
    void start(DownloadManager& manager);
    void pause(DownloadManager& manager);
    void resume(DownloadManager& manager);
    void fail(DownloadManager& manager);
    void printState(); 
};

#endif
