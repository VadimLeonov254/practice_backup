#include<iostream>
#include "notes.h"


Notes::Notes(int size) : size(size){
    notes = new std::string[size];
}

Notes::~Notes(){
    delete[] notes;
}


void Notes::addNote(int i, const std::string& text){
    if( i >= 0 && i < size){
        notes[i] = text;
    }
}

void Notes::printNotes(){
    for(int i = 0; i < size; i++){
        std::cout << notes[i] << std::endl;
    }
}

