#ifndef NOTES_ADVANCED_H
#define NOTES_ADVANCED_H

class Notes{
private:
    int size = 0;
    std::string* notes;
public:
    Notes();
    ~Notes();

    Notes(const Notes& other);

    void addNote(const std::string& text);
    void showNotes();
};


#endif

