#include <iostream>

#include "node.h"
#include "arbitrary_list.h"
#include "arbitrary_list_modified.cpp"

using std::cout;
using std::endl; 

//Let's list them out!
int main(int argc, char **argv) {
    //how do I know that my empty list is working?
    Arbitrary_list my_list;

    //check for a newly created list being empty
    cout << "test that a newly created list is empty!" << endl;
    int new_empty_result = my_list.get_size();
    int expected_new_empty_result = 0;
    if(new_empty_result == expected_new_empty_result) {
        cout << "(test passed) new empty test" << endl;
    }
    else {
        cout << "(test failed) new empty test, expected value: " << expected_new_empty_result << ", but instead received: " << new_empty_result << endl;
    }

    //test that our add method works!
    cout << "test that add works!" << endl;
    my_list.add(42, 0);
    string expected_to_string_result = "42, ";
    string to_string_result = my_list.to_string();
    if(to_string_result.compare(expected_to_string_result) == 0) {
        cout << "(test passed) add test" << endl;
    }
    else {
        cout << "(test failed) add test, expected value: " << expected_to_string_result << ", but instead received: " << to_string_result << endl;
    }

    //test that remove worked
    cout << "test that remove of front node works!" << endl;
    int remove_result = my_list.remove(0);
    int expected_remove_result = 42;
    if(remove_result == expected_remove_result) {
        cout << "(test passed) remove test" << endl;
    }
    else {
        cout << "(test failed) remove test, expected value: " << expected_remove_result << ", but instead received: " << remove_result << endl;
    }

    return 0;
}
