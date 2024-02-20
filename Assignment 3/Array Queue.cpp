#include <iostream>

// queue class
class Queue {
private:
    int head, rear, capacity; // pointers and capacity of array
    int* queue;

public:
    // queue constructer
    Queue(int cap) {
        head = rear = 0; // sets head/rear pointer to 0
        capacity = cap; // sets a max capacity for the queue
        queue = new int[capacity]; // allocates memory/capacity 
    }

    // deletes data/memory in queue
    ~Queue() { delete[] queue; }

    // enqueue function
    void enqueue(int data) {
        if (capacity == rear) { // checks if queue is at capcitiy
            std::cout << "Queue is full\n";
            return;
        }
        queue[rear] = data; // adds data to the rear of queue
        rear++; // moves rear pointer to new position
        std::cout << data << " added to queue\n";
    }

    // dequeue function
    int dequeue() {
        int item = queue[head]; // gets value at front of queue
        for (int i = 0; i < rear - 1; i++) {
            queue[i] = queue[i + 1]; // moves elements one spot towards front of queue
        }
        rear--; // reduces size of queue by one
        return item; // returns value of dequeued element
    }

    // peek function
    int peek() {
        return queue[head]; // returns value at front of queue
    }
};

int main() {
    Queue q(5); // creates queue with capacity of 5

    int input, value;

    // while loop for menu and functions
    while (true) {
        std::cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        std::cout << "Choose a function: ";
        std::cin >> input;

        switch (input) {
            case 1: //enque
                std::cout << "Please enter a new value to add to the queue: ";
                std::cin >> value;
                q.enqueue(value);
                break;
            case 2: //dequeue
                std::cout << "Dequeued: " << q.dequeue() << "\n";
                break;
            case 3: //peek
                std::cout << "Front of queue: " << q.peek() << "\n";
                break;
            case 4: //exit
                std::cout << "See Ya Later!\n";
                return 0;
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    }
}