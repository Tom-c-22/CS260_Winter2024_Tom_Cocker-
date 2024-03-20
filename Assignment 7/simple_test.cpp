// tests for my simple hashtable functions (add, contain, and resize)

#include <iostream>
#include <cassert>
#include "simple_hash.h" 
#include "simple_func.h"

using std::cout;
using std::endl;

void test_hash_function_regular_string() { // test hash w/ string
    HashTable table(10); 
    int hashIndex = table.hash("test");
    assert(hashIndex >= 0 && hashIndex < 10);
    cout << "test_hash_function_regular_string passed. Hash index: " << hashIndex << endl;
}


void test_hash_function_empty_string() { // test hash w/ empty string
    HashTable table(10); 
    int hashIndex = table.hash("");
    assert(hashIndex >= 0 && hashIndex < 10);
    cout << "test_hash_function_empty_string passed. Hash index: " << hashIndex << endl;
}

void test_add_regular_value() { // test add function w/ string
    HashTable table(10); 
    table.add("test");
    assert(table.contain("test") == true);
    cout << "test_add_regular_value passed. Size: " << table.return_size() 
    << ", Collisions: " << table.return_collision_counter() << endl;
}

void test_add_empty_value() { // test add function for adding empty value
    HashTable table(10); 
    table.add("");
    assert(table.contain("") == true);
    cout << "test_add_empty_value passed. Size: " << table.return_size() 
    << ", Collisions: " << table.return_collision_counter() << endl;
}

void test_add_same_value_for_collisions() { // test add function with the same string to check for collisions
    HashTable table(10); 
    table.add("test");
    table.add("test");
    assert(table.return_size() == 1);
    assert(table.return_collision_counter() == 1); 
    cout << "test_add_same_value_for_collisions passed. Size: " << table.return_size()
         << ", Collisions: " << table.return_collision_counter() << endl;
}
void test_contain_existing_value() { // test contain function to check if value exists
    HashTable table(10); 
    table.add("test");
    assert(table.contain("test") == true);
    cout << "test_contain_existing_value passed.\n";
}

void test_contain_non_existing_value() { // test contain function to check for value that DNE
    HashTable table(10); 
    assert(table.contain("test") == false);
    cout << "Test_contain_non_existing_value_passed.\n";
}

void test_resize() { // test for resize function to see if it adjusts to more values
    HashTable table(2); 
    table.add("test1");
    table.add("test2"); 
    table.add("test3"); 
    assert(table.contain("test1") && table.contain("test2") && table.contain("test3"));
    cout << "test_resize_implicit passed. Size: " << table.return_size() 
    << ", Collisions: " << table.return_collision_counter() << endl;
}

int main() {
    test_hash_function_regular_string();
    test_hash_function_empty_string();
    test_add_regular_value();
    test_add_empty_value();
    test_add_same_value_for_collisions();
    test_contain_existing_value();
    test_contain_non_existing_value();
    test_resize();

    cout << "All tests passed.\n";
    return 0;
}