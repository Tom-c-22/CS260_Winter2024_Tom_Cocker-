#include <iostream>

#include "arbitrary_list.h"

using std::cout;
using std::endl;

Arbitrary_list::Arbitrary_list() {
    front = nullptr;
    size = 0;
}

int Arbitrary_list::get_size() {return size;}

    void Arbitrary_list::add(int new_value, int new_position) {
    //some way to add values into my list inserted one position after the position given
    //create generic node, then specialize it later based on our situation
    Node *new_node = new Node{new_value, nullptr};
    Node *current = front;
    //check for empty
    if(current != nullptr){
        //find where the new node should go
        for(int current_position = 0; current_position < new_position && current->next != nullptr; ++current_position) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    } else {
        front = new_node;
    }

    //are we adding before the front?
    if(new_position < 0){
        new_node->next = front;
        front = new_node;
    }
    ++size;
}

//some way to remove values off of my list
    int Arbitrary_list::remove(int old_position) {
        // added code
    // checks if the list is empty
    if (front == NULL) {
        return -1;
    }

    Node *node_to_remove;
    int remove_value;

    if (old_position == 0) { // if loop to check if node is the first in the list
        node_to_remove = front;
        front = front->next;
        remove_value = node_to_remove->value; // stores value of node
        delete node_to_remove; // deletes node
    } else { // if the node is not at the front of the list
        Node *current = front;
        int i = 0; 
        while (i < old_position - 1 && current->next != nullptr) {
            current = current->next; // moves from current node to next node
            ++i;
        }
        if (current->next != nullptr) { // checks if node exists in the list
            node_to_remove = current->next; //if it exists, it's the node that will be removed
            current->next = node_to_remove->next; //moves next pointer to following node
            remove_value = node_to_remove->value; //stores value of node
            delete node_to_remove;
        } else {
            return -1; 
        }
    }

    --size;
    return remove_value; // return value of removed node
}

int Arbitrary_list::get(int position) {
    //added code
    if (position < 0 || position >= size) { // checks if the position in the list exists (greater than 0 and less than size)
        return -1;
    }

    Node *current = front;
    int i = 0;
    while (i < position) { // while loop to go through the list
        current = current->next; // moves from current node to next node
        ++i; // increases value of i by 1 each time
    }

    return current->value;
}

string Arbitrary_list::to_string() {
    string result = "";

    //gather list values as a string
    Node *current = front;

    while(current != nullptr) {
        result = result + std::to_string(current->value) + ", ";
        current = current->next;
    }

    return result;
}
