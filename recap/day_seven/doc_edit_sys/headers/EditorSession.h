#ifndef EDITORSESSION_H
#define EDITORSESSION_H
#include<memory>
#include "Document.h"
#include "User.h"

class User;

class EditorSession{
private:
    std::weak_ptr<Document> doc;
    std::unique_ptr<User> editor;

public:
    EditorSession(std::weak_ptr<Document> doc, std::unique_ptr<User> editor);
    void openDocument();    
    void closeDocument();
    void writeDocument(std::string text);
    void readDocument();
};

#endif
