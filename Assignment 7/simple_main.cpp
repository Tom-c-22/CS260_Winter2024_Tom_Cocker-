#include <iostream>
#include "simple_func.h"

int main() {
    int initial_capacity;
    std::cout << "Enter initial capacity for the hash table: ";
    std::cin >> initial_capacity;

    HashTable table(initial_capacity); // creates a hash table with initial capacity
    int choice;
    std::string value; // value the user enters, using std::string for compatibility with HashTable

    while (true) { // while loop until user chooses to exit
        std::cout << "\n1. Add a value\n2. Check if a value exists\n3. Display size and collision count\n4. Exit Program\n"; // Updated menu options
        std::cout << "Pick an option: ";
        std::cin >> choice; // takes user choice as input

        switch (choice) { // uses user's choice
            case 1: { // add (option 1)
                std::cout << "Enter a value you'd like to add: ";
                std::cin >> value; // takes user input value
                int result = table.add(value); // calls add function with value
                if (result == 0) {
                    std::cout << value << " has been added.\n";
                } else {
                    std::cout << "Failed to add " << value << ".\n";
                }
                std::cout << "Current size: " << table.return_size() << "\n";
                std::cout << "Number of collisions: " << table.return_collision_counter() << "\n";
                break;
            }
            case 2: { // check existence (option 2)
                std::cout << "Enter a value you'd like to check: ";
                std::cin >> value; // takes user input value
                bool exists = table.contain(value); // calls contain function with value
                if (exists) {
                    std::cout << value << " exists in the table.\n";
                } else {
                    std::cout << value << " does not exist in the table.\n";
                }
                break;
            }
            case 3: { // display size and collision count (option 3)
                std::cout << "Size: " << table.return_size() << "\n";
                std::cout << "Number of collisions: " << table.return_collision_counter() << "\n";
                break;
            }
            case 4: { // exit (option 4)
                std::cout << "Exiting program.\n";
                return 0;
            }
            default: { // prompt if the user doesn't enter a valid choice from the menu
                std::cout << "That isn't an option, try again!\n";
            }
        }
    }
}