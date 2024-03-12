Arbitrary List Additions: 

For the arbitrary list class, I added both a remove function and get function to ensure the tests passed. 
While it may not be the most efficient (while loops), the tests all came back as passed! 

Lines 44-71: This section of code includes my add function. 
Lines 79-91: This section of code includes my get function. 

-------------------------------------------------------------------------------------------------------------------------------

Auto-Sorted List: 

I was able to use a lot of code from previous assignments for this which was convenient. Previously, I had been using my main function to do testing via the menu. Entering different values/positions to test the functionality of each function. This time I used your test file as a layout to test each function as well as the menu I've had previously. 

(list_function.h)
Lines 3-21: This section of code is just my node struct, linked list class structure and initialization. 

Lines 23-36 (Insert Function): This section of code uses if statements and a while loop to check if the list is empty (value will be placed at head), and traverse the list, comparing each value already in the list with the value being inserted to find the correct position (sorted in ascending integer order).

Lines 38-55 (Remove Function): This section uses similar if statements and a while loop to check if the list is empty, if the node to be removed is the first in the list, and then the traversal of the list to find the value and remove the node. 

Lines 57-66 (Search Function): This function, again, starts at the beginning of the list, using a while loop and incrimented counter to move through the list, checking each value until the value is found and returned. 

(test.cpp)
Tests: This file contains all my tests for inserting, removing, and searching for values in/into the list. 

Lines 14-67: This section includes multiple tests that check my insert function. It tests for the insertion of 1 value, another value, then a value into the middle, a value before the head value, a value at the end, and a matching values. 

Lines 69-106: This section includes tests that check my remove function. It tests for the removal of an existing node, a node that doesn't exist, the removal of the head node, a node in the middle, and removal of the only node in the list. 

Lines 108-126: This section is for test of my search function. It only tests the search of a value that exists and a value that doesn't exist. 

-------------------------------------------------------------------------------------------------------------------------------

Complexity: 

For each one of my functions, I use a while loop that traverses the entire list to find the position/value of the node we'd like to remove or search. For the insert function, the list must be travesed so the inserted value can be inserted in the correct position (insertion sort). The BigO notation for each function, due to these while loops, would be O(n). The functions, with their while loops, traverse the list with "n" values. As the number of values(elements) increases, so does the time/number of operations. 