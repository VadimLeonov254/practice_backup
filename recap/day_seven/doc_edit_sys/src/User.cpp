#include<iostream>
#include<vector>
#include<memory>
#include<vector>
#include "User.h"
#include "EditorSession.h"


void User::addSession(std::unique_ptr<EditorSession> session){
    sessions.push_back(std::move(session));  
};
