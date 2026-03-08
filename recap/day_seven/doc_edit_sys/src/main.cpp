#include <iostream>
#include <memory>
#include "Document.h"
#include "EditorSession.h"
#include "User.h"

int main(){

    auto doc1 = std::make_shared<Document>("Mom");
    auto doc2 = std::make_shared<Document>("Dad");
    auto doc3 = std::make_shared<Document>("Son");

    auto user = std::make_unique<User>();

    EditorSession session1 = EditorSession(doc1, std::move(user)); 
    
    session1.openDocument();
    session1.writeDocument("Hello, mom!");
    session1.closeDocument();

    session1.readDocument();

}
