#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include<vector>
#include<memory>
#include "File.h"

class FileManager{
private:
    std::vector<std::unique_ptr<File>> files;

public:
    FileManager();
    int fileCount();    
    void addFile(std::unique_ptr<File> file);
    void deleteFile();
};

#endif
