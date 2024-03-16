
#include "bst_node.h"

class BST {

    public:
    node *root;
    node *locate_parent(int new_data);
    node *lowest_value(node *start);
    void in_order_traversal_helper(node *current);
    

    public:
        BST();
        void add(int new_value);
        int remove(int old_value);
        bool search(int proposed_value);
        void in_order_traversal();
};