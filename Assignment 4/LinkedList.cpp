#include <iostream>

struct node { // node struct
    int value;  // // data stored in the node
    node *next; // pointer to next node in list

    node(int val) : value(val), next(nullptr) {} // node constructor 
};

class linked_list { // class for linked list
private:
    node *head; // head of list pointer 
    int size;   // number of elements in the list 

public:
    linked_list() : head(nullptr), size(0) {} // constructs empty link list 

    ~linked_list() { // list destructor
        node *cur_node = head;
        while (cur_node != nullptr) {
            node* next = cur_node->next; // keeps track of next node in list
            delete cur_node; // deletes current node
            cur_node = next;             // goes to next node in list
        }
    }

    bool empty() const { // checks if the list is empty
        return head == nullptr;
    }

    void add(int value, int position) { // add function
        if (position < 0 || position > size) { // checks if position is valid
            std::cout << "Try again from position 0 to " << size << ".\n"; //error message if position DNE
            return;
        }

        node* new_node = new node(value); // creates new node with user entered value

        if (position == 0) { // checks if node should be added to head of list
            new_node->next = head; // updates head pointer
            head = new_node; 
        } else { // 
            node *temp = head; //places temporary node at head the list
            for (int i = 0; i < position - 1; i++) { //node traverses list until reaching position
                temp = temp->next; 
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
        size++; 
        print_list(); // prints the new list after adding value
    }

    int remove(int position) { // remove function
        if (empty()) { // checks if the list is empty
            std::cout << "The list is empty right now.\n";
            return -1;
        }
        if (position < 0 || position >= size) { // checks if selected positioin is currently in the list
            std::cout << "Position doesn't exist in the list.\n";
            return -1;
        }

        node *temp = head; // starts at head
        int rem_value;  // removed node value

        if (position == 0) { 
            head = head->next; // moves head pointer to next node if head node is removed
            rem_value = temp->value; 
            delete temp;               
        } else { 
            for (int i = 0; i < position - 1; i++) { //traverses until reaching node before position
                temp = temp->next;
            }
            node *rem_node = temp->next;  
            temp->next = rem_node->next;  
            rem_value = rem_node->value; 
            delete rem_node;              
        }
        size--; // decreases size of list when node is removed
        print_list(); // prints the new list after removing a value
        return rem_value; // prints value of removed node
    }

    int get(int position) { // get function
        if (position < 0 || position >= size) { // checks if selected positioin is currently in the lsit
            std::cout << "Position doesn't exist in the list.\n";
            return -1;
        }

        node* temp = head; 
        for (int i = 0; i < position; i++) { //traverses list to get position
            temp = temp->next;
        }
        return temp->value; 
    }

    void print_list() { // function to print entire list for reference of node position/value
        node* current = head; 
        while (current != nullptr) { 
            std::cout << current->value << " -> "; 
            current = current->next; 
        }
        std::cout << "(empty)\n"; // 
    }
};

int main() { //main function
    linked_list my_list;
    int choice, value, position;

    while (true) { // while loop for menu and functions
        std::cout << "\n1. Add\n2. Remove\n3. Get\n4. Exit\n";
        std::cout << "Choose a function: "; 
        std::cin >> choice;

        switch (choice) {
            case 1: // add option
                std::cout << "Enter a value to add: ";
                std::cin >> value; //user entered value
                std::cout << "Enter a position to insert at: ";
                std::cin >> position; //user entered position
                my_list.add(value, position); //uses add function with user entered data
                break;
            case 2: // remove option
                std::cout << "Enter a position to remove: ";
                std::cin >> position; //user entered position
                my_list.remove(position); //uses remove function with user entered position
                break;
            case 3: // get option
                std::cout << "Enter a position to get: ";
                std::cin >> position; //user entered position
                value = my_list.get(position); //uses get function with user entered position
                if (value != -1) {
                    std::cout << "Value at position " << position << ": " << value << "\n";
                }
                break;
            case 4: // exit option
                std::cout << "Exiting program.\n";
                return 0;
            default: 
                std::cout << "Invalid choice, please try again.\n"; //invalid choice prompt
        }
    }
    return 0; 
}