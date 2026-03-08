#ifndef DOWNLOADSTATE_H
#define DOWNLOADSTATE_H

class DownloadManager;

class DownloadState{

public:
    virtual void start(DownloadManager& manager) = 0;
    virtual void pause(DownloadManager& manager) = 0;
    virtual void resume(DownloadManager& manager) = 0;
    virtual void fail(DownloadManager& manager) = 0;
    virtual void printState() = 0;

    virtual ~DownloadState() = default; 

};

#endif
