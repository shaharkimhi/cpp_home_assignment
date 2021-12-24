## Answers to home assignment in cpp

### Queston1
#### task 1:
push_back has linear time complexity when reallocations happens, so it's less effective to put it in for loop. So, I improved fill_vector by using iota function which its time complexity is linear in the distance between first and last. 
In addition, I improved vecOfvec.push_back by creating the vector from fill_vector only once and then push it to vecOfvec 10 times as requested.
#### task 2:
To implement count_total_elements without "visible" for loop, I used for_each function. for_each calls sumSizeVector which sums up each vector's size to a global variable called "sum".
#### task 3:
I implement merge_vec_of_vec by using "move" algorithm which moves all elements in each vector to vecOfvec.

### Queston2
First, I created two threads - one for operation1 and the other for operation2. Then, I uses join function on the two threads in order to make one thread of execution wait for another thread to finish running. 
**** continue ****

### Question3
The memory leak is in dispacher_thread function. This function creating Payload object without deleting it at the end of the program run. To fix it, I created Payload object in the main function and deleted it after the thread occurs.

### Question4
In order to make sure that the program can run in other windows, linux and other platforms I uses "\" in files names (I read that Windows accepts both forward- and backslash as path separator).

### Question5
I added a Circle class that has a center point and radius fields and Shape class that both Circle and Rectangle inherit from.


