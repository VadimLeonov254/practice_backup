#include<iostream>
#include "dyn_notes.h"

int main(){
    std::string note, answer;
    Notes book = Notes();
    

    while(answer != "no"){

        std::cout << "Do you want to add a note? (yes/no)" << std::endl;
        std::cin >> answer;
        
        if(answer == "yes"){
            std::cout << "Enter your note: ";
            std::cin >> note;
        
            char* text = new char[note.length()+1];
            for(int i = 0; i < note.length(); i++){
                text[i] = note[i];
            }
            
            text[note.length()] = '\0';

            book.addNote(text);


        }
    }
    std::cout << "Your notes: " << std::endl;
    book.showNotes(1);
}
