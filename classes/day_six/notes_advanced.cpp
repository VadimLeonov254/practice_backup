#include<iostream>
#include "notes_advanced.h"

Notes::Notes(){
    notes = new std::string[size];
}

Notes::Notes(const Notes& other){

    notes = new std::string[size];

    for(int i = 0; i < size; i++){
        notes[i] = other.notes[i];
    }    

}

Notes::~Notes(){
    delete[] notes;
}

void Notes::addNote(const std::string& text){
    size++;
    std::string* data = new std::string[size];
    for(int i = 0; i < size-1; i++){
        data[i] = notes[i];
    }
    
    delete[] notes;

    notes = data;
    notes[size-1] = text;
}

void Notes::showNotes(){
    if (size == 0){
        std::cout << "There are no notes!" << std::endl;
    }else{
        for(int i = 0; i < size; i++){
            std::cout << i+1 << ": " << notes[i] << std::endl;
        }
    }
}
