README to show code requirements and analyze complexity: 

Lines 13-29: Linked list class including a constructor that initializes and empty list and a list destructor to remove allocated memory from the list when nodes are deleted. 

Lines 37-58: An add function that uses value and position parameters to add a specific value into a specific position in the list. Given the user is entering the value and position, the function checks if the position currently exists in the list. If the position is valid, it is checked whether it is the head of the list or not. If so, value is added to the head of the list, if not, the temp node is placed at head of the list and traverses the list until user netered position is found. List is updated and printed. 

Lines 61-91: Similar to the add function, the remove function checks if the list is empty (can't remove a value from an empty list) and checks if the suer entered postion is valid. The function starts at the head of the list and finds the value of the removed node. The function also checks if the head node is the one selected to be removed. If not, the list is traversed until the position is reached. The removed nodes value is stored, the rem node is deleted, the lists size is then adjusted and printed. 

Lines 93-104: The get function uses the user entered position to locate and print the value of the node in the position. Using a temporary pointer to move through the list to the user entered position, storing and printing the value of the node at the temproary header.

Lines 117-154: The main function uses value, position, and choice(user entered choices) to execute the add, remove, and get functions, allowing for the adjustment of list. Using the menu option also allows for ease of testing to ensure the functions/list works properly. Reprinting the list after every modification shows if each function worked properly.

-------------------------------------------------------------------------------------------------------------------------------

BigO/Complexity Analysis: 

The add, remove, get, and print functions all are O(n) because they are dependent on the size of the list. The add, remove, and get functions involve traversing the list to find a position via a for loop which means this iteration must happen "n" times until the position is reached. This traversal to find the position where a value is going to be added, removed, and retrieved is the only section of these functions that are O(n). 

The while loop I used in the list destructor is O(n) as it must destruct "n" nodes so it's dependent on the size of the list. 

The print function is also O(n) due to the while loop I used because it must print "n" nodes and the loop goes through "n" iterations until reaching an empty node. 

The main function is also O(n) due to the while loop used to run program until the user chooses to exit. 

I believe all the other lines are technically O(1) regardless of input size. Although there might be several steps in any given line, the time remains constant.



