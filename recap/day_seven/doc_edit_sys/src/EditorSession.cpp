#include<iostream>
#include<memory>
#include "Document.h"
#include "EditorSession.h"
#include "User.h"

EditorSession::EditorSession(std::weak_ptr<Document> doc, std::unique_ptr<User> editor) : doc(doc), editor(std::move(editor)) {}

void EditorSession::openDocument(){
    auto d = doc.lock();
    if(!d){
        std::cout << "Unable to enter editor session" << '\n';
        return;
    }
    if(!d->getLocked()){
        d->toggleLock();
        std::cout << "Document has been opened" << '\n';
    }
};

void EditorSession::closeDocument(){
    auto d = doc.lock();
    if(!d){
        std::cout << "Unable to enter editor session" << '\n';
        return;
    }
    if(d->getLocked()){
        d->toggleLock();
        std::cout << "Document has been closed" << '\n';
    }
};

void EditorSession::writeDocument(std::string text){
    auto d = doc.lock();
    if(d){
        d->write(text);
    }else{
        std::cout << "Document no longer exists" << '\n';
    }
};

void EditorSession::readDocument(){
    auto d = doc.lock();
    if(d){
        d -> read();
    }else{
        std::cout << "Document no longer exists" << '\n';
    }
};
