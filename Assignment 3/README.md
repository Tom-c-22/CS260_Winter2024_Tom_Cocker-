README file to show code requirments: 

Linked List Queue:

lines 4-10: The node's are structured for a linked list data structure. Each node is given a value and a pointer to the next node in the list. 

Lines 13-23: The queue class gives the data structure a first in, first out (FIFO) using a head pointer for the first node in the queue and a rear pointer at the last node in the queue. 

Lines 26-34: The enqueue function creates and checks if it is the first node to be entered into the queue. Using lines 72-76, the user inputs an integer that is applied to the value of the new node. This node is then added to the rear of the queue and is passed the rear pointer. 

Lines 37-51: The dequeue function removes the head element at the front of the queue unless the queue is empty. The dequeued node is given a temporary pointer and is removed from the queue. The value of the dequeued node is then displayed and deleted. 

Lines 54-59: The peek function first checks if the queue is empty. If it's empty, there isn't a node to check the value of. If there's even a single node in the queue, that node will be at the head of the queue, so the value of that node will be displayed. 

The tests/outputs worked correctly and can be viewed in the "Linked List Queue Terminal Testing" png located in the same folder as this README. 

I tested the enqueue function with a variety of integers, the dequeue function until the queue was empty, and the peek function when there was values in the queue and when the queue was empty.

--------------------------------------------------------------------------------------------------------------------------------

