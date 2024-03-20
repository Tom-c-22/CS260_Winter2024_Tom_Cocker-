Final Project Requirments: 

1. My project design and description of how a graph structure could be solve some kind of problem is in my Final_Design.jpg located in my final project folder. 

2. I thought up some tests before starting which can be seen in my Test_Design.jpg in my final project folder. I chose not to use the cycle test for Kruskal's algorithm and chose to impliment code which eliminated a cycle (lines 86-94) by checking the node and it's set/group. When an edge will be added to the mst, this code verifies it's source and destination nodes aren't in the same set, avoiding a cycle. 

3. 
(1) Lines 36-43: My add node function that takes a letter, checks if that letter exists in the graph already, and adds the node. 

(2) Lines 45-65: My add edge function that checks the weight and ensures it's valid (a positive integer) and finds the source/destination node pointers and checks if an edge between the two nodes already exists. If it's not a duplicate, has a valid weight and has two nodes the edge is created.

(3) Lines 76-103: My Kruskal's algorithm checks if the graph is empty, initializes union_find which helps check for cycles, sorts the edges in the graph by weight and then finds their associated source and destination node index. Each source/destination node is checked if they belong in the same set which would result in cycles. If the edge creating a cycle is found, although it might be the lowest weight, must be removed from possible mst edges. The mst edges are added to a vector, their weights are added, then the total weight of the mst is displayed. 

(4) Lines 105-145: My Dijkstra's algorithm checks if the source node exists and finds it. The edges weights are set to infiniti and all nodes in the graph are declared unvisited. The priority queue is used to store the weight between nodes and index of the source node. Essentially ordering the nodes by the lowest weight from the source node. This stops when all nodes have been visisted and the shortest path is displayed.  

----------------------------------------------------------------------------------------------------------------------

Time Complexity Analysis: 

Add Node Function: This function would have be O(n) where n is the number of nodes in the graph. This is because it traverses through all the nodes in the graph to ensure the new node isn't a duplicate of an existing node. 

Add Edge Function: This function calls find_node twice to find the source and destination nodes with each time being O(n) where n represents the number of nodes. Worst case it has to traverse through the every node. After the source and destination nodes are found, the vector containing the edges is then traversed which is also O(n). 

Kruskal's Algorithm: This function/algorithm loops through all the edges of the graph and uses the find function twice and the unite function when needed. The sort function sorts all the edges in the graph by their weight which results in O(n log n) where n is the number of edges in the graph. Traversing the sorted edges results in O(n) where n is the number of edges in the graph. The find and unite function calls also result in O(n log n) making the worst case for this algorithm O(n log n).

Dijkstra's Algorithm: The function/algorithm utilizes a priority queue and min-heap to easily find the smallest weight edge from the source node. When a smaller weight path is found, that edge goes into the queue. Insertions into the priority queue have a time complexity of O(log n), with n representing the total nodes in the graph. As each edge could be a potential new edge in thee path, each edge could potentially be inserted too which leads to a time complexity of O(e log n) where e represents the edges and n represents the nodes. Worst case would be O(n log n).

