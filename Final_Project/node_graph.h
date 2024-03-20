#pragma once

#ifndef NODE_GRAPH_H  
#define NODE_GRAPH_H  

#include <vector>

struct Edge; // edge struct declaration 

struct Node { // node struct
    char letter; // using letters as identifiers for the nodes
    std::vector<Edge*> edges;  // edges stored in vector 

    Node(char a) : letter(a) {} // node constructor
};

#endif 