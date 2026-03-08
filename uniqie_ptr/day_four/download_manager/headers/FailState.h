#ifndef FAILSTATE_H
#define FAILSTATE_H

#include "DownloadState.h"
#include "DownloadManager.h"
class FailState : public DownloadState{
public:
    void start(DownloadManager& manager);
    void pause(DownloadManager& manager);
    void resume(DownloadManager& manager);
    void fail(DownloadManager& manager);
    void printState();

};

#endif
