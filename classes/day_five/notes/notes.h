#ifndef NOTES_H
#define NOTES_H

class Notes{

private:
    std::string* notes;
    int size;

public:
    
    Notes(int size);
    ~Notes();
    void addNote(int i, const std::string& text);
    void printNotes();

};

#endif
