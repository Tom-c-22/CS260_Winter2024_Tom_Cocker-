#include "class_graph.h"
#include "functions_graph.h"

int main() {
    Graph graph;
    // graph construction with 10 nodes and 15 edges (for now)
    graph.add_node('A');
    graph.add_node('B');
    graph.add_node('C');
    graph.add_node('D');
    
    graph.add_edge('A', 'B', 6);
    graph.add_edge('A', 'C', 3);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('C', 'D', 1);
    graph.add_edge('B', 'D', 4);

    graph.display();  // displays the graph
    graph.kruskals_mst(); // display kruskals mst and total weight
    graph.dijkstras('A'); // displays dijkstra's shortest path from A

    return 0;
}