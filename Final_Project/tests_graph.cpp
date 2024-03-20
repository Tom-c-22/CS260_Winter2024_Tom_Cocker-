
#include <cassert>
#include <iostream>
#include "functions_graph.h" // Adjust the include path according to your project structure

using std::cout;
using std::endl;

void test_add_node() {
    Graph g;
    g.add_node('A');
    assert(g.find_node('A') != nullptr);
    cout << "test_add_node for existing node passed! \n";
}

void test_add_duplicate_node() {
    Graph g;
    g.add_node('A');  
    g.add_node('A');  
    Node *nodeA = g.find_node('A'); 
    assert(nodeA != nullptr);  
    cout << "test_add_duplicate_node passed! \n";
}

void test_add_edge() {
    Graph g;
    g.add_node('A');
    g.add_node('B');
    g.add_edge('A', 'B', 10);
    Node *nodeA = g.find_node('A');
    assert(!nodeA->edges.empty());
    assert(nodeA->edges.front()->weight == 10);
    assert(nodeA->edges.front()->destination == g.find_node('B'));
    cout << "test_add_edge with valid nodes passed! \n";
}

void test_add_duplicate_edge() {
    Graph g;
    g.add_node('A');
    g.add_node('B');
    g.add_edge('A', 'B', 6);
    g.add_edge('A', 'B', 10); 
    g.display(); // graph should only have A - (6) - B
    cout << "test_add_edge_between_same_nodes passed if graph only shows A - 6 - B! \n";
}

void test_add_edge_positive_weights() {
    Graph g;
    g.add_node('A');
    g.add_node('B');
    g.add_node('C');
    g.add_edge('A', 'B', 5);
    g.add_edge('B', 'C', -1);
    g.display(); // graph should contain only A and B nodes with edge weight 5
    std::cout << "test_add_edge_positive_weights passed if graph only contains A - 5- B! \n";
}

void test_display() {
    Graph g;
    g.add_node('A');
    g.add_node('B');
    g.add_edge('A', 'B', 5);
    g.display(); //graph should display A - (5) - B
    cout << "test_display passed! \n";
}

void test_kruskals_mst() {
    Graph g;
    g.add_node('A');
    g.add_node('B');
    g.add_node('C');
    g.add_node('D');
    g.add_node('E');
    g.add_edge('A', 'B', 1);
    g.add_edge('A', 'C', 5);
    g.add_edge('B', 'C', 3);
    g.add_edge('C', 'D', 4);
    g.add_edge('E', 'C', 2);
    g.kruskals_mst(); // should return 10 for total weight
    cout << "test_kruskals_mst passed if total weight = 10! \n";
}

void test_kruskals_mst_empty() {
    Graph g;
    g.kruskals_mst(); // should return "graph is empty message"
    cout << "test_kruskals_mst_empty passed if empty graph message is displayed! \n";
}

void test_dijkstras() {
    Graph g;
    g.add_node('A');
    g.add_node('B');
    g.add_node('C');
    g.add_node('D');
    g.add_node('E');
    g.add_node('F');
    g.add_node('G');
    g.add_node('H');
    g.add_edge('A', 'B', 1);
    g.add_edge('A', 'C', 5);
    g.add_edge('A', 'H', 3);
    g.add_edge('B', 'E', 7);
    g.add_edge('C', 'D', 2);
    g.add_edge('C', 'F', 8);
    g.add_edge('D', 'G', 4);
    g.add_edge('E', 'D', 5);
    g.add_edge('F', 'G', 3);
    g.add_edge('H', 'C', 7);
    g.add_edge('H', 'F', 2);
    g.dijkstras('A'); // should be 0,1,5,7,8,5,8,3
    cout << "test_dijkstras passed if all nodes are reached by lowest path!\n";
}

void test_dijkstras_negative() {
    Graph g;
    g.add_node('A');
    g.add_node('B');
    g.add_node('C');
    g.add_node('D');
    g.add_node('E');
    g.add_edge('A', 'B', -1);
    g.add_edge('A', 'C', 5);
    g.add_edge('B', 'D', -3);
    g.add_edge('C', 'D', 4);
    g.add_edge('B', 'E', 2);
    g.dijkstras('A'); // if A-B and A-E fail, test passed
    cout << "test_dijkstras_negative passed if A-B and A-E failed! \n";
}

int main() {
    test_add_node();
    test_add_duplicate_node();
    test_add_edge();
    test_add_duplicate_edge();
    test_add_edge_positive_weights();
    test_display();
    test_kruskals_mst();
    test_kruskals_mst_empty();
    test_dijkstras();
    test_dijkstras_negative();

    cout << "All tests passed.\n";
    return 0;
}