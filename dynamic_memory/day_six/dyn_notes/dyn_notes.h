#ifndef dyn_notes_h
#define dyn_notes_h

class Notes{
private:
    char** notes;
    int len = 1;
public:
    Notes();
    ~Notes();

    void addNote(char* words);
    void showNotes();
};

#endif
