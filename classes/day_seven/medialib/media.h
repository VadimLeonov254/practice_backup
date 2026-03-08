#ifndef MEDIA_H
#define MEDIA_H

class MediaLibrary{

private:
    int size;
    char* title;

public:
    
    MediaLibrary(int size);
    ~MediaLibrary();

    MediaLibrary(const MediaLibrary& other);

    void printInfo();
    void giveTitle(std::string name);

};


class Song : public MediaLibrary{

private:
    int duration;
    std::string name;
    
public:
    Song(int duration, std::string name, int size);
    void getSong();
};


#endif 
