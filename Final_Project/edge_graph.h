#pragma once

#ifndef EDGE_GRAPH_H  
#define EDGE_GRAPH_H 

struct Node; // node struct declaration 

struct Edge { // edge struct
    Node *source = nullptr; // pointer to source node
    Node *destination = nullptr; // pointer to destination node
    int weight = 0; // weight of edge

    Edge(Node *src, Node *dest, int w) : source(src), destination(dest), weight(w) {} // edge constructor
};

#endif 
