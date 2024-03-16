
Binary Search Tree: 

I included jpg files of my design and a snippet of my tests passing. 

(bst_node.h)
Lines 2-8: This file is my node struct. The nodes store a value (int) and have two pointers (left and right).

(bst_functions.h)
Lines 31-34: My add function that takes the value and determines if it is the first node in the tree. If it isn't 
the value is evaluated to be less than or equal to, or greater than the root node and is moved to the left or right. I used
the left side of my tree to store values that are less than or equal to the root and the right side of the tree for values greater than the root. 

Lines 46-104: My remove function checks if the node exists and uses different methods on finding the node and determining
if the node has no child nodes, one child node, or two child node and rebalances the tree depending on the circumstance. 
The lowestvalue function is utilized to find the "successor" node which is the lowest value in the right side of the tree. The value of the successor node replaces the value of the value that's being removed and the successor node is removed. 

Lines 121-134: the in_order_traversal function calls the in_order_traversal_helper function with the root node as the starting point for traversal. The traversal then moves all the way left, then all the way to right, printing the sequence.

---------------------------------------------------------------------------------------------------------

Complexity: 

For an ordered binary search tree, the insert function would be O(log n). The function must traverse the bst but the steps in finding the position would be cut in half due to the structure of a bst. Each value inserted would need to go one of two ways, left (less than or equal to), or right (greater than). This is continued until the insertion position is reached with the traversal going from root -> insertion node instead of traversing every node. This is the same for the search function. The value being searched for is compared to root node and goes left or right continuously until the node is reached. 

Compared to an unordered BST, a search function would require searching the entire tree to find the value because it can't be reduced to greater than, less than, or equal to. An insert function would be the same, as the entire tree would be traversed to find the insertion location of a given value.