#ifndef SCOPEDFILE_H
#define SCOPEDFILE_H
#include<fstream>
#include<memory>

class ScopedFile{
private:
    std::unique_ptr<std::fstream> file;
    bool open = false;

public:
    ScopedFile(std::string fileName, std::string action);
    std::string readLine();
    void writeLine(const std::string& line);
    bool isOpen();

};

#endif
