#include <cassert>
#include <iostream>
#include "list_function.h" // list header file

using std::cout;
using std::endl;

void test_autosort_list_constructor() { //constructor test
    linked_list my_list;
    assert(my_list.search(0) == -1); 
    cout << "test_autosort_list_constructor passed.\n";
}

void test_autosort_list_insert_first_node() { // insert one node into the list
    linked_list my_list;
    my_list.insert(1);
    my_list.display();
    assert(my_list.search(1) == 0); // nodes position should be 0 if node was inserted
    cout << "test_autosort_list_insert_first_node passed.\n";
}

void test_autosort_list_insert_second_node() { // insert second node into the list
    linked_list my_list;
    my_list.insert(1);
    my_list.insert(2);
    my_list.display();
    assert(my_list.search(2) == 1); // nodes position should be 1 if node was inserted in order
    cout << "test_autosort_list_insert_second_node passed.\n";
}

void test_autosort_list_insert_node_after_end() { // insert node at the end of the list
    linked_list my_list;
    my_list.insert(1);
    my_list.insert(2);
    my_list.insert(5);
    my_list.display();
    assert(my_list.search(5) == 2); // nodes position should be 2 if node was inserted in order
    cout << "test_autosort_list_insert_node_after_end passed.\n";
}

void test_autosort_list_insert_node_with_same_value_as_head() { // insert node that has same value as first node
    linked_list my_list;
    my_list.insert(1);
    my_list.insert(2);
    my_list.insert(1);
    my_list.display();
    assert(my_list.search(1) == 0); // same value node should be put at head of list
    cout << "test_autosort_list_insert_node_with_same_value_as_head passed.\n";
}

void test_autosort_list_insert_node_before_head() { // insert node with lowest value to be put at head
    linked_list my_list;
    my_list.insert(1);
    my_list.insert(-1); 
    my_list.display();
    assert(my_list.search(-1) == 0); // new nodes position should be 0 as it's lowest value 
    cout << "test_autosort_list_insert_node_before_head passed.\n";
}

void test_autosort_list_insert_node_in_middle_of_list() { // insert node in the middle of the list
    linked_list my_list;
    my_list.insert(1);
    my_list.insert(5);
    my_list.insert(3);
    my_list.display();
    assert(my_list.search(3) == 1); // node should be placed in middle, between position 0 and 2
    cout << "test_autosort_list_insert_node_in_middle_of_list passed.\n";
}
void test_autosort_list_remove_existing_node() { // removes node in list
    linked_list my_list;
    my_list.insert(1);
    my_list.insert(2);
    my_list.insert(3);
    my_list.remove(2); 
    my_list.display();
    assert(my_list.search(2) == -1); // node should be out of the list
    cout << "test_autosort_list_remove_existing_node passed.\n";
}

void test_autosort_list_remove_head_node() { // removes node at head of list
    linked_list my_list;
    my_list.insert(1);
    my_list.insert(2);
    my_list.remove(1); 
    my_list.display();
    assert(my_list.search(1) == -1); // new head node after removal 
    cout << "test_autosort_list_remove_head_node passed.\n";
}

void test_autosort_list_remove_node_not_in_list() { // test to check value not in list cannot be removed
    linked_list my_list;
    my_list.insert(1);
    my_list.insert(2);
    my_list.remove(3); 
    my_list.display();
    assert(my_list.search(1) != -1 && my_list.search(2) != -1); // nothing should change
    cout << "test_autosort_list_remove_node_not_in_list passed.\n";
}

void test_autosort_list_remove_only_node() { // removes only node 
    linked_list my_list;
    my_list.insert(1);
    my_list.remove(1); 
    assert(my_list.search(1) == -1); // list should be empty
    cout << "test_autosort_list_remove_only_node passed.\n";
}

void test_autosort_list_search() { // searches for existing value
    linked_list my_list;
    my_list.insert(1);
    my_list.insert(2);
    my_list.insert(3);
    int position = my_list.search(2);
    assert(position == 1); 
    cout << "test_autosort_list_search passed.\n";
}

void test_autosort_list_search_dne() { // searches for -non-existing value
    linked_list my_list;
    my_list.insert(1);
    my_list.insert(2);
    my_list.insert(3);
    int position = my_list.search(4);
    assert(position == -1); 
    cout << "test_autosort_list_search_dne passed.\n";
}

int main() { // main
    test_autosort_list_constructor();
    test_autosort_list_insert_first_node();
    test_autosort_list_insert_second_node();
    test_autosort_list_insert_node_after_end();
    test_autosort_list_insert_node_with_same_value_as_head();
    test_autosort_list_insert_node_before_head();
    test_autosort_list_insert_node_in_middle_of_list();
    test_autosort_list_remove_existing_node();
    test_autosort_list_remove_head_node();
    test_autosort_list_remove_node_not_in_list();
    test_autosort_list_remove_only_node();
    test_autosort_list_search();
    test_autosort_list_search_dne();

    cout << "All tests passed.\n";
    return 0;
}