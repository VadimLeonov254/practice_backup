#ifndef GRAPH_CYCLES_H
#define GRAPH_CYCLES_H
#include<memory>
#include<vector>


class Node{
private:
    int id;
    std::vector<std::shared_ptr<Node>> neighbors;
    
public:
    Node(int id);

    void addNeighbor(std::shared_ptr<Node> neighbor);
    int reachableCount();
};

#endif
