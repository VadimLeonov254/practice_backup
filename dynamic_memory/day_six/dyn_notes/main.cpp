#include<iostream>
#include "dyn_notes.h" 


int main(){
    
    std::string notes;
    Notes book = Notes();
    std::cout << "Enter the note you want to add below:" << std::endl;
    
    std::cin >> notes;
    
    char* note = new char[notes.length()+1];
    
    for(int i = 0; i < notes.length(); i++){
        note[i] = notes[i];
    }
    
    note[notes.length()] = '\0';

    book.addNote(note);
    
    book.showNotes();

}
