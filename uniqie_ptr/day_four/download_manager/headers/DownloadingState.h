#ifndef DOWNLOADINGSTATE_H
#define DOWNLOADINGSTATE_H

#include "DownloadState.h"
#include "DownloadManager.h"
class DownloadingState : public DownloadState{

public:
    void start(DownloadManager& manager);
    void pause(DownloadManager& manager);
    void resume(DownloadManager& manager);
    void fail(DownloadManager& manager);
    void printState();

};

#endif
