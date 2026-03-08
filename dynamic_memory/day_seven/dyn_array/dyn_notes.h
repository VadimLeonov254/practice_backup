#ifndef DYN_NOTES_H
#define DYN_NOTES_H

class Notes{
    
private:
    char** notes;
    int size = 0;
public:
    Notes();
    ~Notes();

    void addNote(char* note);
    void showNotes(int i);

};

#endif
