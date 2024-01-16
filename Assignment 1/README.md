Modelling a bag of marbles: 

1. A normal, non-magical bag can't store infinite number of marbles, so there has to be a set limit to how many marbles the bag can hold.

2. The user can select how many marbles they'd like to store in the bag/vector. 

3. The user will then choose how many marbles they'd like to remove from the bag, prompting them to enter a new number if they select a number higher than the marble count in the bag.

4. After choosing a number of marbles they removed, they will be notified how many marbles remain in the bag.

5. Using a vector stores the marbles. The user entered amount of marbles are then added/removed from the vector.

6. The vector will store marbles in a sequence when added. When removed, they will be removed in reverse order they were added in. This works well because the marbles have no attributes. If the the marbles had attributes and we didn't use any kind of random selection methods, the last marble added would always be the marble chosen when a single marble was picked out of the bag. 

7. Attributes (color, size, material) could also be assigned to the marbles which gives more specific information on which marbles were removed. 

8. Adding x amount of randomly attributed marbles, then removing one randomly selected marble would also resemble a bag, as reaching in blindly and selecting a marble would result in a random marble.

9. For my code, I will add x amount of marbles and remove x amount of marbles, allowing the user to decide the number of marbles they'd like to add/remove. 



Lines of code: 

Lines 15 - 21 & 41 - 47 fulfill the requirment of being able to add marbles into the bag/vector. Together, they prompt the user to enter an amount of marbles (count) they would like to add. It then checks to see if the number entered is too large (returns false) or if it is below the max capacity (50) and adds it to the vector using push.back. 

Lines 24 - 29 & 52 - 58 fulfill the requirment of being able to remove marbles from the bag/vector. Together, they prompt the user to enter an amount of marbles they would like to remove (count). It then checks to see if there are that many marbles in the bag. If there aren't enough marbles in the bag, it will return false and prompt the user to reenter a number. If the number is within the bag.size, the number will be removed from the vector. 

Line 8 - 11: The bag class uses a vector to store the data. Adding the data in a sequence and then removing the data in a reverse order. (The first object entered is the last to be removed, the last entered object is the first to be removed). The bag class also sets the max capacity of the bag to 50. I included prompts when the user attempts to add a number larger than 50. 

![Alt text](image.png)