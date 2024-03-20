#ifndef CLASS_GRAPH_H
#define CLASS_GRAPH_H

#include "node_graph.h"  
#include "edge_graph.h"  
#include <vector>        
#include <algorithm>     
#include <limits>        


class union_find { // union find class
    std::vector<int> parent;  // vector to store parent node
    std::vector<int> rank;    // vector to store rank of node

public:
    union_find(int n); // union find constructor
    int find(int x); // find parent of node x 
    void unite(int x, int y); // unite sets with x and y 
};

class Graph { // graph class
    std::vector<Node*> nodes;  // vector of node pointers
    std::vector<Edge*> edges;  // vector of edge pointers
    std::vector<Edge*> mst_edges;  // vector for mst edges

public:
    Graph();  // graph class constructor
    ~Graph(); // graph class destructor

    static const int INF = std::numeric_limits<int>::max(); // const for infinity for djikstras
    void add_node(char letter); 
    void add_edge(char source_letter, char dest_letter, int weight);
    void display() const;
    void kruskals_mst();
    void dijkstras(char source_letter);

    Node *find_node(char letter); // find a node by it's letter indicator

private:
    int node_index(Node* node); // find index of nodes in node vector
};

#endif 
