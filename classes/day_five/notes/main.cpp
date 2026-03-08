#include<iostream>
#include "notes.h"

int main(){
    
    int size;
    std::string note;
    std::cout << "Enter the size of your notebook: "; 
 
    std::cin >> size;

    std::cin.ignore();
    Notes book = Notes(size);

    for(int i = 0; i < size; i++){
        std::cout << "Enter the note at page " << i+1 << std::endl;
        std::cin >> note;
        book.addNote(i, note);  
    }
    
    std::cout<<std::endl;

    book.printNotes();

}
