#include <iostream>
#include "bst_class.h"

using std::cout;
using std::endl;

BST::BST() { // constructs empty tree 
    root = nullptr;
}

node *BST::locate_parent(int new_data) { // function to find parent node of value
    if (root == nullptr) {
        return nullptr; // the tree is empty when root node dne
    }
    node *current = root;
    while (current->left != nullptr || current->right != nullptr) {
        if (new_data <= current->data && current->left == nullptr) {
            break; // no left child so new node is now parent of left
        } else if (new_data > current->data && current->right == nullptr) {
            break; // no right child so new node is now parent of right
        } else if (new_data <= current->data) {
            current = current->left; // node is moved to left if less than or equal to parent/root
        } else {
            current = current->right; // node is moved to right if greater than to parent/root
        }
    }
    return current; 
}

void BST::add(int new_data) { // add function that inserts node in correct position
    node *new_node = new node(new_data); // creates new node w/ data, left pointer, and right pointer

    if (root == nullptr) { // when the tree is empty, the new node becomes the root node
        root = new_node; 
    } else { // locate parent node if tree isn't empty
        node *parent = locate_parent(new_data);
        if (new_data <= parent->data) { // if new data is less than or equal to parent node data
            parent->left = new_node; // new node assigned to left side of tree
        } else {
            parent->right = new_node; // new node assigned to right side of tree
        }
    }
}

node* BST::lowest_value(node *start) { // function for finding lowest value node
    node *current = start;
    while (current && current->left != nullptr) { 
        current = current->left;
    }
    return current;
}

int BST::remove(int old_value) { // function for removing value and associated node form tree 
    node *current = root; // start at root node
    node *parent = nullptr; // track parent node 
    while (current != nullptr && current->data != old_value) { // while loop to find the value/node user wants to remove
        parent = current; // assigns parent node to current node
        if (old_value <= current->data) { 
            current = current->left; // moves to left child if user entered value is less than or equal to current node value
        } else {
            current = current->right; // moves to right if greater than or equal to
        }
    }
    if (current == nullptr) { // checks if user entered value/node was found
        return 0; 
    }
    if (current->left == nullptr && current->right == nullptr) { // checks if user entered value/node has children nodes
        if (current == root) { // if root node, set root to null
            root = nullptr;
        } else if (parent->left == current) { // if left child node, set parent node left pointer to null
            parent->left = nullptr; 
        } else { // if right child node, set parent node right pointer to null
            parent->right = nullptr;
        }
        delete current; // deletes node containing user entered value 
    }
    else if (current->left == nullptr || current->right == nullptr) { // checks if node has one child node
        node *child = (current->left != nullptr) ? current->left : current->right; // gets child node
        if (current == root) { // child becomes new root if node was root
            root = child;
        } else if (parent->left == current) { // updates parent node pointers to left child
            parent->left = child; 
        } else { // updates parent node pointers to right child
            parent->right = child;
        }
        delete current; // deletes node with containing user entered value
    }
    else {
        node *successor = lowest_value(current->right); // locates smallest value in right tree
        current->data = successor->data; // moves value from successor node to node containing user chosen value
        node *temp_parent = current; // create new pointer and assign pointer to current node
        while (temp_parent->right != nullptr && temp_parent->right != successor) { 
            temp_parent = temp_parent->right; // traverses right side of tree until successor node 
        }
        if (successor->right != nullptr) { // if successor node has right child, parent node gets pointer
            temp_parent->right = successor->right;
        } else { // if no right child node, parent node right pointer set to null
            temp_parent->right = nullptr;
        }
        delete successor; // deletes successor node
    }
    return 0; 
}

bool BST::search(int proposed_value) { // search function
    node *current = root;
        while(current != nullptr) { // traverses tree until reaching null
            if(proposed_value == current->data) { //compares value we're searching for to current node
                return true;
            } else if(proposed_value <= current->data) { // if statement for is value is less than or equal to current value
                current = current->left; // move left of current node to smaller values
            } else {
                current = current->right; // move right of current node to larger values
            }
        }
        return false; // returns false if the value isn't found within the tree
    }

void BST::in_order_traversal() {
    in_order_traversal_helper(root); // calls helper function with root as starting node
}
void BST::in_order_traversal_helper(node* current) {
    if (current != nullptr) {
        in_order_traversal_helper(current->left);  // traverse through left subtree
        std::cout << current->data;  // visit current node
        if (current->right != nullptr || (current != root && current != root->right)) { //check if last node to avoid comma
            std::cout << ", "; 
        }
        in_order_traversal_helper(current->right);  // traverse through right subtree
    }
}