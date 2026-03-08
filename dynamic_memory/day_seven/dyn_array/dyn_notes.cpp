#include<iostream>
#include "dyn_notes.h"

Notes::Notes(){
    notes = new char*[size];
}


Notes::~Notes(){
    if(size != 1){
        for(int i = 0; i < size; i++){
            delete[] notes[i];
        }
    }
    delete[] notes;
}

void Notes::addNote(char* note){
    size++;
    if (size == 1){
        char** data = new char*[1];
        data[0] = note;
        delete[] notes;
        notes = data;

    }else{
        char** data = new char*[size];
        for(int i = 0; i < size; i++){
            data[i] = notes[i];
        }
        data[size-1] = note;
        delete[] notes;
        notes = data;

    }
}

void Notes::showNotes(int i){
    for(int i = 0; i < size; i++){
        std::cout << notes[i] << std::endl;
    }
}

