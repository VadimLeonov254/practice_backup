#ifndef USER_H
#define USER_H
#include<vector>
#include<memory>
#include "EditorSession.h"
#include "Document.h"

class EditorSession;

class User{
private:
    std::vector<std::unique_ptr<EditorSession>> sessions;

public:
    void addSession(std::unique_ptr<EditorSession> session);
};

#endif
