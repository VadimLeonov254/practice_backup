#ifndef TOOL_H
#define TOOL_H

class Tool{

private:
    std::string name;
    bool in_use = false;

public:
    Tool(std::string name);
    void use();
    bool isUsed();
    std::string getName();
};

#endif
