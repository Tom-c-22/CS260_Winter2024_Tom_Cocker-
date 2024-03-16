
struct node { // node struct
    int data; // data/value in node
    node *left; // pointer for left (less tahn or equal to)
    node *right; // pointer for right (greater than)

    node(int val) : data(val), left(nullptr), right(nullptr) {} // node constructor
};

