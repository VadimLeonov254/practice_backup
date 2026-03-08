#include<iostream>
#include<memory>
#include<vector>
#include"graph_cycles.h"

Node::Node(int id) : id(id){}

void Node::addNeighbor(std::shared_ptr<Node> neighbor){
    neighbors.push_back(neighbor);
    neighbors.insert(neighbors.begin(), neighbor);
}

int Node::reachableCount(){
    return neighbors.size();
}

