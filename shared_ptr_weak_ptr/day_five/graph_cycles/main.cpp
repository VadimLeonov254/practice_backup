#include<iostream>
#include<memory>
#include"graph_cycles.h"

int main(){

    auto A = std::make_shared<Node>(6); 
    auto B = std::make_shared<Node>(4); 
    auto C = std::make_shared<Node>(10); 
    A -> addNeighbor(B);
    B -> addNeighbor(C);
    C -> addNeighbor(A);
    
    std::cout << A -> reachableCount() << '\n';

}
