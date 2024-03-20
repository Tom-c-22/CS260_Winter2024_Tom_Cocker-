#include "class_graph.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

union_find::union_find(int n) : parent(n), rank(n, 0) { // initialize vectors
    for (int i = 0; i < n; ++i) parent[i] = i; // each node is its own parent
}

int union_find::find(int x) { // returns root parent of x using path compression
    if (x != parent[x]) parent[x] = find(parent[x]);
    return parent[x];
}

void union_find::unite(int x, int y) { // unites sets with x and y unless they are in the same set
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return;

    if (rank[rootX] < rank[rootY]) { // combine small rank tree w/ large rank tree
        std::swap(rootX, rootY);
    }
    parent[rootY] = rootX; // make rootX the parent of rootY
    if (rank[rootX] == rank[rootY]) rank[rootX]++;
}

Graph::Graph() = default; // graph constructor
Graph::~Graph() { // graph destructor
    for (Node *node : nodes) delete node;
    for (Edge *edge : edges) delete edge;
}

const int Graph::INF;

void Graph::add_node(char letter) { // add function
    Node *previous_node = find_node(letter); // check if the node with indicator already is in the graph
    if (previous_node == nullptr) {
        nodes.push_back(new Node(letter)); // add new node
    }
    else {
        return; // if node exists, don't add node
    }
}

void Graph::add_edge(char source_letter, char dest_letter, int weight) { // add edge between two nodes
    if (weight <= 0) {
        return; // don't add edge if weight is negative
    }

    Node *source = find_node(source_letter); // find source node
    Node *destination = find_node(dest_letter); // find destination node

    if (source && destination) {
        auto it = std::find_if(source->edges.begin(), source->edges.end(), // check if edge already exists
            [destination](Edge *edge) { return edge->destination == destination; });

        if (it == source->edges.end()) { // if edge doesn't exist
            Edge *new_edge = new Edge(source, destination, weight);
            edges.push_back(new_edge); // add new edge 
            source->edges.push_back(new_edge); // add new edge to source nodes edges
        }
        else {
            return; // do nothing if there's already an edge between the nodes
        }
    }
}

void Graph::display() const { // formats and displays graph
    std::cout << "Graph:\n";
    for (const auto& node : nodes) {
        for (const auto& edge : node->edges) {
            std::cout << node->letter << " - (" << edge->weight << ") - " << edge->destination->letter << "\n";
        }
    }
}

void Graph::kruskals_mst() { // Kruskal's algorithm 
    mst_edges.clear(); // remove previous mst edges
    if (nodes.empty()) { // check if graph is empty
        std::cout << "The graph is empty!\n";
        return;
    }
    union_find uf(nodes.size()); // initialize union_find with one element for each node

    sort(edges.begin(), edges.end(), [](Edge *a, Edge *b) { return a->weight < b->weight; }); // sort edge by ascending weight

    for (Edge *edge : edges) {
        int u = node_index(edge->source); // find index of source node
        int v = node_index(edge->destination); // find index of destination node

        if (uf.find(u) != uf.find(v)) { // if source and destination nodes not in same set, combine
            uf.unite(u, v); // unite sets of source and destination nodes
            mst_edges.push_back(edge); // add edge to mst_edges 
        }
    }

    std::cout << "\nMinimum Spanning Tree:\n";
    int final_weight = 0; // starting weight of mst
    for (const auto& edge : mst_edges) { // go through each edge of mst
        std::cout << edge->source->letter << " - " << edge->destination->letter << " (" << edge->weight << ")\n";
        final_weight += edge->weight; // add edges weight to total weight 
    }
    std::cout << "Total weight of MST: " << final_weight << "\n";
}

void Graph::dijkstras(char source_letter) { // Dijkstra's algorithm
    Node *source = find_node(source_letter); // find source node
    if (!source) { // if there's no source node, display error 
        cout << "Couldn't find the source node!" << endl;
        return;
    }

    vector<int> dist(nodes.size(), INF); // set weight of all edges to infinite
    vector<bool> visited(nodes.size(), false); // set all nodes to unvisited
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int sourceIndex = node_index(source); // find source node index
    dist[sourceIndex] = 0;
    pq.push({0, sourceIndex});

    while (!pq.empty()) { // while priority queue contains elements
        int u = pq.top().second; // find index of node with lowest weight edge
        pq.pop(); // remove node from priority queue

        if (visited[u]) continue;
        visited[u] = true; // if already visited, set to visited

        for (Edge *edge : nodes[u]->edges) { // go over all edges of node
            int v = node_index(edge->destination); // get index of destination node
            int weight = edge->weight; // get edges weight

            if (dist[u] + weight < dist[v]) { // if there's an option with less weight
                dist[v] = dist[u] + weight; // change added weight
                pq.push({dist[v], v}); // add destination node to queue with new edge
            }
        }
    }

    cout << "\nDijkstra's Shortest Path from " << source_letter << ":\n";
    for (size_t i = 0; i < nodes.size(); ++i) { // check all nodes
        if (dist[i] == INF) // if the node doesn't have an edge or can't be reached
            cout << source_letter << " - (failed) - " << nodes[i]->letter << "\n";
        else
            cout << source_letter << " - (" << dist[i] << ") - " << nodes[i]->letter << "\n";
    }
}

Node *Graph::find_node(char letter) { // finds node using its indicator letter
    for (Node *node : nodes) {
        if (node->letter == letter) 
            return node; // Return the node if the letter matches
    }
    return nullptr; // Return nullptr if no matching node is found
}

int Graph::node_index(Node *node) { // returns node index from graphs node list
    for (size_t i = 0; i < nodes.size(); ++i) {  // check all nodes
        if (nodes[i] == node) return i;  // return nodes index if it exists
    }
    return -1; 
} 