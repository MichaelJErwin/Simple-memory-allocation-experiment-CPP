# Simple-memory-allocation-experiment-CPP
This is a simple memory allocation experiment.

The program 'data' will create a simple vector-like data structure that uses realloc() 
to manage dynamic resizing. An int pointer array is used to store elements. I've 
hardcoded to insert elements into the structure that will branch to the resizing logic. 
Then, I compare this structure to the vector structure in the standard library by timing 
the tasks for both structures. 

For both structures, I will insert: 

- The value 20 at index 30   
- The value 40 at index 100
- The value 812 at index 60,000

Both structures start out with the capacity to hold 100 items. The program displays 
the value, index, and size of the structure after each insertion. 

Inserting into my structure:   
If there is not enough capacity, increase size to desired insertion index + 1. 
Example: Size 100 has indices 0-99, so when I try to insert into index 100, the struct 
is resized to a size of 101.

Inserting into a std::vector:   
Insertion will increase the size of the vector by 1 which is why after the insertions 
the std::vector has sizes 101, 102, and then 60,001, respectively. Before the third 
insertion, I need to manually resize the std::vector to a size of 60,000 before I can 
insert into it or else there is a segmentation fault. 
