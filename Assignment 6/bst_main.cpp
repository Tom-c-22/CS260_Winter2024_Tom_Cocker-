#include <iostream> 
#include "bst_functions.h"


int main() {
    BST tree; // creates binary search tree
    int choice, value; // choice from menu option and value the user enters

    while (true) { // while loop until user chooses to exit
        std::cout << "\n1. Insert a value\n2. Remove a value\n3. Search for a value\n4. Display tree in-order\n5. Exit Program\n"; // Updated menu options
        std::cout << "Pick an option: ";
        std::cin >> choice; // takes user choice as input

        switch (choice) { // uses user's choice
            case 1: { // insert (option 1)
                std::cout << "Enter a value you'd like to insert: ";
                std::cin >> value; // takes user input value
                tree.add(value); // calls add function with value
                break;
            }
            case 2: { // remove (option 2)
                std::cout << "Enter a value you'd like to remove: ";
                std::cin >> value; // takes user input value
                bool removed = tree.remove(value); // calls remove function with value
                if (removed) {
                    std::cout << value << " has been removed.\n";
                } else {
                    std::cout << value << " could not be found.\n";
                }
                break;
            }
            case 3: { // search (option 3)
                std::cout << "Enter a value you'd like to find: ";
                std::cin >> value; // takes user input value
                bool found = tree.search(value); // calls search function with value
                if (found) {
                    std::cout << value << " was found in the tree.\n";
                } else {
                    std::cout << value << " wasn't found in the tree.\n";
                }
                break;
            }
            case 4: { // display tree (in order traversal) (option 4)
                std::cout << "Tree's values in-order:\n";
                tree.in_order_traversal(); // calls the in_order function to display tree
                break;
            }
            case 5: { // exit (option 5)
                std::cout << "See Ya Later!\n";
                return 0;
            }
            default: { // prompt if the user doesn't enter a valid choice from the menu
                std::cout << "That isn't an option, try again!\n";
            }
        }
    }
}