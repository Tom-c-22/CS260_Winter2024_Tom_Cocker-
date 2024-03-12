#include <iostream>

struct node { // node struct
    int data; // data stored in node
    node *next; // pointer to next node
    node(int val) : data(val), next(nullptr) {} // node constructor
};

class linked_list { // linked list class
private:
    node *head; // pointer for head node

public:
    linked_list(); 
    void insert(int data); 
    void remove(int data);
    int search(int data); 
    void display() const;
};

linked_list::linked_list() : head(nullptr) {} 

void linked_list::insert(int data) { // insert function that sorts integers in ascending order 
    node *new_node = new node(data); // creates node with the given data
    if (head == nullptr || data < head->data) { // if statement for if the node is the first node in list
        new_node->next = head; 
        head = new_node; 
    } else {
        node *current = head; 
        while (current->next != nullptr && current->next->data < data) { // moves through list to find insert position based on value
            current = current->next; // moves to next node 
        }
        new_node->next = current->next; 
        current->next = new_node; 
    }
}

void linked_list::remove(int data) { // remove function that removes node from position
    if (head == nullptr) return; // checks if list is empty
    node *current = head;
    node *prev = nullptr;

    if (current->data == data) { // // if statement for if the node is the first node in list
        head = current->next; // node after becomes new head
        delete current; 
        return; }
    while (current != nullptr && current->data != data) { // moves through list to find the value 
        prev = current; // updates previous node
        current = current->next; // moves to next node
    }
    if (current != nullptr) { // checks current node exists
        prev->next = current->next; // skips over current node
        delete current;
    }
}

int linked_list::search(int data) { // linear search method starting from beginning of list
    node *current = head; 
    int position = 0; 
    while (current != nullptr) { // while loop until value is found
        if (current->data == data) return position; 
        current = current->next; 
        position++; // moves counter up 1 each time loop is iterrated 
    }
    return -1; // case for if the value isn't found
}

void linked_list::display() const { // display function to show the user the current list
    node *current = head; 
    if (current == nullptr) { // checks if list is empty       
        return; 
    }
    std::cout << "Current list: ";
    while (current != nullptr) { // loops through entire list
        std::cout << current->data;
        if (current->next != nullptr) std::cout << ", "; // prints comma to keep readability
        current = current->next; // moves to next node
    }
    std::cout << std::endl; // prints empty line after to keep readability
}