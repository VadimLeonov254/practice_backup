#include<iostream>
#include "dyn_notes.h"

Notes::Notes(){
    notes = new char*[len];
}

Notes::~Notes(){

    for (int i = 0; i < len; i++) {
        delete[] notes[i];
    }

    delete[] notes;
}

void Notes::addNote(char* words){
    
    int l = 0;
    while(words[l]){
        l++;
    }
    char* newNote = new char[l + 1];
    for (int i = 0; i < l; i++) {
        newNote[i] = words[i];
    }
    newNote[l] = '\0';

    notes[len-1] = newNote;
    len++;

}

void Notes::showNotes(){
    
    for(int i = 0; i < this -> len; i++){
        int l = 0; 
        while(notes[i][l]){
            std::cout << notes[i][l];
            l++;
        }
        std::cout << std::endl;
    }
}
