#include <iostream>
#include <vector> 

// a class for marbles with no specific attributes/properties
class Marble {};

// a class for the bag that uses a vector to store the marbles in sequence
class Bag {
private:
    std::vector<Marble> marbles; 
    static const int maxCapacity = 50;  // sets the max # of marbles that can be stored

public:
    // function to add marbles to bag/vector
    bool addMarbles(int count) {
        // determines if amount of marbles added exceeds max
        if (marbles.size() + count > maxCapacity) 
        { return false; } // if number exceeds max, returns false
        // puts user entered # of marbles in bag/vector in sequence
        for (int i = 0; i < count; ++i) { marbles.push_back(Marble()); }
        return true;
    }

    // function to remove marbles from bag/vector
    bool removeMarbles(int count) {
        if (count > marbles.size()) 
        { return false; } // determines if there are enough marbles in bag
        // takes out user entered # of marbles from bag/vector in sequence
        for (int i = 0; i < count; ++i) { marbles.pop_back(); }
        return true; 
    }

    // function to check # of marbles in bag/vector
    int size() const { return marbles.size(); }
};

// main function that calls other functions and prints respective prompts/messages after loops
int main() {
    Bag bag;
    int add_marbles, rem_marbles;

    // while loop that prompts user to enter marbles to the bag
    while (true) {
        std::cout << "How many marbles do you want to put in the bag? (MAX = 50) ";
        std::cin >> add_marbles;

        if (bag.addMarbles(add_marbles)) { break; } // stops loop if user input is less than max capacity
        else { std::cout << "That's too many marbles!!!" << std::endl; } // loops back if user input exceeds capacity
    }

    std::cout << "Now there are " << bag.size() << " marbles in the bag!" << std::endl; // lets user know how many marbles are in the bag (bag.size) via console me

    // while loop that prompts user to remove marbles from the bag 
    while (true) {
        std::cout << "How many marbles do you want to take out of the bag? ";
        std::cin >> rem_marbles;

        if (bag.removeMarbles(rem_marbles)) { break; } // stops loop if user input is less than or equal to bag.size
        else { std::cout << "You only put " << bag.size() << " marbles in the bag!" << std::endl; } // loops back if user input exceeds bag.size and outputs respective message in concole
    }

    std::cout << "Now there's only " << bag.size() << " marbles left in the bag!" << std::endl; // lets the user know (bag.size) after adding and removing marbles in console

    return 0;
}