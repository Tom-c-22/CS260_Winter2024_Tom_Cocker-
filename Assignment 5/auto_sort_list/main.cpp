#include <iostream>
#include "list_function.h" // header file

int main() {
    linked_list myList;
    int choice, value; // choice from menu option and value the user enters
 
    while (true) { // while loop until user chooses to exit
        std::cout << "\n1. Insert a value\n2. Remove a value\n3. Search for a value\n4. Exit Program\n"; // menu options
        std::cout << "Pick an option: ";
        std::cin >> choice; // takes user choice as input

        switch (choice) { // uses user's choice
            case 1: { // insert (option 1)
                std::cout << "Enter a value you'd like to insert: ";
                std::cin >> value; // takes user input value
                myList.insert(value); // calls insert function and takes value
                myList.display(); // shows user full list after additions
                break; 
            }
            case 2: { // remove (option 2)
                std::cout << "Enter a value you'd like to remove: ";
                std::cin >> value; // takes user input value
                myList.remove(value); // calls remove function and takes value
                myList.display(); // shows user full list after removal 
                break;
            }
            case 3: { // search (option 3)
                std::cout << "Enter a value you'd like to find: ";
                std::cin >> value; // takes user input value 
                int position = myList.search(value); // calls search function and takes value
                if (position != -1) { // if loop for if the value is/isn't found
                    std::cout << value << " was found at position: " << position << "\n"; 
                } else { 
                    std::cout << value << " wasn't found in the list. Try something else!\n"; 
                }
                break; 
            }
            case 4: { // exit (option 4)
                std::cout << "See Ya Later!\n"; 
                return 0; 
            }
            default: { // prompt if the user doesn't enter a valid choice from the menu
                std::cout << "That isn't an option, try again!\n"; 
            }
        }
    }
}