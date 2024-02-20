#include <iostream>

// node struct 
struct node {
    int value;  // data stored in the node
    node* next; // pointer to next node in list

    // node constructor 
    node(int val) : value(val), next(nullptr) {}
};

// queue class with a linked list
class queue {
private:
    node* head; // head of queue pointer
    node* rear;  // rear of queue pointer

public:
    queue() : head(nullptr), rear(nullptr) {} // constructs empty queue

    bool empty() const { 
        return head == nullptr; // if head ptr is null, queue is empty
    }

    // enqueue function
    void enqueue(int value) {
        node* new_node = new node(value); // creates new node
        if (head == nullptr) {
            head = rear = new_node; // head and rear pointers point to new node if queue is empty
        } else {
            rear->next = new_node; // links new node to rear of queue
            rear = new_node; // new node becomes the new rear
        }
    }

    // dequeue function
    int dequeue() {
        if (empty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return -1; // indicates queue is empty, return an error value
        }
        node* temp = head; // temp pointer for head node
        int dequeuedValue = head->value; // store the value of the dequeued node
        head = head->next; // moves head pointer to next node

        if (head == nullptr) {
            rear = nullptr; // if queue becomes empty, set rear to nullptr
        }

        delete temp; // deletes the dequeued node
        return dequeuedValue; // returns the value of the dequeued node
    }

    int peek() const {
        if (empty()) {
            std::cout << "The queue is empty.\n";
            return -1; // indicates if queue is empty
        }
        return head->value; // returns value at head of queue
    }
};

int main() {
    queue qi; // queue instance 
    int input, value; // user input for choice and value

    while (true) {
        std::cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        std::cout << "Choose a function: ";
        std::cin >> input;

        switch (input) {
            case 1:
                std::cout << "Please enter a new value to add to the queue: ";
                std::cin >> value;
                qi.enqueue(value);
                break;
            case 2: {
                int dequeuedvalue = qi.dequeue();
                if (dequeuedvalue != -1) {
                    std::cout << "Dequeued: " << dequeuedvalue << "\n";
                }
                break;
            }
            case 3:
                if (!qi.empty()) {
                    std::cout << "Front of queue: " << qi.peek() << "\n";
                } else {
                    std::cout << "Queue is empty.\n";
                }
                break;
            case 4:
                std::cout << "See ya later!\n";
                return 0;
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    }
}