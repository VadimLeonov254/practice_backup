#include<iostream>
#include "notes_advanced.h"

int main(){
    
    Notes book;
    std::string answer, note;
    book.showNotes();
    
    while(answer != "no"){
        std::cout << "Do you want to add a note (yes/no)?" << std::endl;
        std::cin >> answer;
        if(answer == "yes"){
            std::cout << "Enter the note: " << std::endl;
            std::cin >> note;
            book.addNote(note);
        }
    }
    
    book.showNotes();

}
