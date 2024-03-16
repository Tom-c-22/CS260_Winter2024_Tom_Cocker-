#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include "bst_functions.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;

void test_bst_constructor() { // test for initial tree construction
    BST tree;
    assert(tree.root == nullptr); // root node should be null
    cout << "test_bst_constructor passed.\n";
}

void test_bst_add_root_node() { // test for the addition of the root node/first node
    BST tree;
    tree.add(10);
    assert(tree.root != nullptr && tree.root->data == 10); // only value in tree
    assert(tree.root->left == nullptr && tree.root->right == nullptr); // both should be null
    cout << "test_bst_add_root_node passed.\n";
}

void test_bst_add_series_of_nodes() { // tests add function when a series of nodes are added
    BST my_tree;
    my_tree.add(10); // root node
    my_tree.add(5);  // left parent node
    my_tree.add(15); // right parent node
    my_tree.add(3);  // left child of 5
    my_tree.add(7);  // right child of 5
    my_tree.add(12); // left child of 15
    my_tree.add(17); // right child of 15
    // tests values are inserted in correct order 
    assert(my_tree.root->left->data == 5);
    assert(my_tree.root->right->data == 15);
    assert(my_tree.root->left->left->data == 3);
    assert(my_tree.root->left->right->data == 7);
    assert(my_tree.root->right->left->data == 12);
    assert(my_tree.root->right->right->data == 17);
    cout << "test_bst_add_series_of_nodes passed.\n";
}

void test_bst_remove_leaf_node() { // test that removes node with no children
    BST my_tree;
    my_tree.add(10); // root node
    my_tree.add(5);  
    my_tree.remove(5);
    assert(my_tree.root->left == nullptr); // there should only be the root node left
    cout << "test_bst_remove_leaf_node passed.\n";
}

void test_bst_remove_node_with_one_child() { // test that removes node with one child
    BST my_tree;
    my_tree.add(10); // toot node
    my_tree.add(5);  // node that will be removed
    my_tree.add(3);  // only child node that will replace the 5
    my_tree.remove(5);
    assert(my_tree.root->left->data == 3); // 3 should now be in place of 5
    cout << "test_bst_remove_node_with_one_child passed.\n";
}

void test_bst_remove_node_with_two_children() { // test that removes node with two children
    BST my_tree;
    my_tree.add(10);  // root node
    my_tree.add(5);   // node that will be removed
    my_tree.add(3);   // left child
    my_tree.add(7);   // right child
    my_tree.remove(5);
    assert(my_tree.root->left->data == 7); // 7 should replace 5 in the tree
    assert(my_tree.root->left->left->data == 3); // 3 should be the left child of 7
    cout << "test_bst_remove_node_with_two_children passed.\n";
}

void test_bst_search_value() { // test for searching for a value that exists in tree
    BST tree;
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(7);
    assert(tree.search(7) == true); // should return true
    std::cout << "test_bst_search_value passed.\n";
}

void test_bst_search_non_existing_value() { // test for searching for a value that DNE in the tree
    BST tree;
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(7);
    assert(tree.search(100) == false); // should return false
    std::cout << "test_bst_search_non_existing_value passed.\n";
}
int main() { // main
    test_bst_constructor();
    test_bst_add_root_node();
    test_bst_add_series_of_nodes();
    test_bst_remove_leaf_node();
    test_bst_remove_node_with_one_child();
    test_bst_remove_node_with_two_children();
    test_bst_search_value();
    test_bst_search_non_existing_value();

    cout << "All tests passed.\n";
    return 0;
}