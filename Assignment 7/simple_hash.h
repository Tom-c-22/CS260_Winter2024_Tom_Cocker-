#ifndef SIMPLE_HASH_H
#define SIMPLE_HASH_H

#include <iostream>
#include <string>

using std::string;

class HashTable {
public:
    HashTable(int initial_capacity); // constructor with set initial capacity
    ~HashTable(); // destructor 

    int hash(string value); // input string, stored as integer in endex
    int add(string value);
    int return_size() const; // returns number of values stored in hash table
    int return_collision_counter() const; // returns number of collision that have happened
    bool contain(string value); // checks if value is currently in the hashtable

private:
    bool resize(); // resizes hashtable for more elements
    int capacity; // capacity of hashtable
    int size; // number of keys in hashtable
    int collision_counter; // number of collisions 
    string *storage = nullptr; // pointer to storage/index
};

#endif