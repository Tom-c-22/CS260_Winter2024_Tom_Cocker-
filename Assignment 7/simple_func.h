#include <iostream>
#include "simple_hash.h"
using std::string;

HashTable::HashTable(int initial_capacity) {
    capacity = initial_capacity;
    size = 0; // initialize size
    collision_counter = 0; // initialize collision count
    storage = new string[capacity];
}

HashTable::~HashTable() {
    delete[] storage; // destructor for hash table
}

int HashTable::hash(string value) { // hash function to convert string into index value
    int hash = 0; // set initial hash value to 0
    for (char c : value) { // loop through each character of string
        hash = hash * 31 + c; // claculate hash value by taking hash value, multiply by 31 (prime), and adding each char's value
    }
    return hash % capacity; // modulo operation to make sure hash value fits within bounds
}

int HashTable::add(string value) { 
    if (size >= capacity * 0.6) { // resize when 60% full
        if (!resize()) {
            return -1; // return -1 if resizing didn't work
        }
    }
    int bucket = hash(value); // hash value

    if (!storage[bucket].empty() && storage[bucket] != value) { // check for collision 
        collision_counter++; // add to collision counter
    } else if (storage[bucket] != value) {
        size++;
    }

    storage[bucket] = value; // store value in bucket
    return bucket; 
}

bool HashTable::resize() {
    int old_capacity = capacity; // store old capacity
    capacity *= 2; // double capacity of table

    string* old_storage = storage; // keep the pointer to the old storage
    storage = new string[capacity]; // create new string array with new capacity

    for (int i = 0; i < capacity; ++i) { // mark empty positions in storage with empty string
        storage[i] = "";
    }

    size = 0; // reset size to 0
    for (int i = 0; i < old_capacity; ++i) { // move through old array
        if (!old_storage[i].empty()) { // only add slots with values
            add(old_storage[i]); // call add function to rehash values and add to table
        }
    }
    delete[] old_storage; // delete the old storage
    return true;
}

bool HashTable::contain(string value) {
    int index = hash(value); // hash the string to get the index
    if (storage[index] == value) { // check bucket with same index
        return true; 
    }
    return false; // return false if it isn't found
}

int HashTable::return_size() const { // return size of hashtable
    return size; 
}
int HashTable::return_collision_counter() const { // return number of collisions
    return collision_counter; 
}
