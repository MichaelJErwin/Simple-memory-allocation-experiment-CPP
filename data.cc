//Michael Erwin

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <vector>

//vector-like data structure 
typedef struct
{
    //int pointer array that originally has space for 100 ints
    int* arr = (int *) malloc(100 * sizeof(int));
    //initial size is 100
    int size = 100;
    //to add an item. position is the index to insert into
    void addVal(int position, int value)
    {
    	//if the index trying to insert into is greater than or equal to the size
    	//arr needs to be reallocated
    	if(position >= size)
    	{
    		//position + 1 so that the size is right
    		arr = (int *) realloc(arr, (position + 1) * sizeof(int));
    		//insert value into newly allocated array
    		arr[position] = value;
    		//update size value
    		size = position + 1;
    	}
    	//else put value into position
    	else
    	{
    		arr[position] = value;
    	}
    }
    //return value at index
    int getVal(int position)
    {
    	return arr[position];
    }
    //return current size
    int getSize()
    {
    	return size;
    }
    //free the memory
    void _free()
    {
    	free(arr);
    }
    
} vector_like;//name of struct



int main(int argc, const char* argv[])
{
    
	//Using my vector-like structure below
   
    vector_like v;
    
	std::cout << "My struct: " << std::endl << std::endl;
	
    //wall clock time
    auto t_start1 = std::chrono::high_resolution_clock::now();
	
    //put the value 20 in the index 30
    v.addVal(30, 20);
    //display value, index, and size 
    std::cout << "Value: " << v.getVal(30) << std::endl;
	std::cout << "Index: 30" << std::endl;
	std::cout << "Size:  " << v.getSize() << std::endl;
    std::cout << std::endl;
    
    //put the value 40 in the index 100
    v.addVal(100, 40);
    //display value, index, and size
    std::cout << "Value: " << v.getVal(100) << std::endl;
	std::cout << "Index: 100" << std::endl;
	std::cout << "Size:  " << v.getSize() << std::endl;
    std::cout << std::endl;
    
    //put the value 812 in the index 60,000
    v.addVal(60000, 812);
    //display value, index, and size 
    std::cout << "Value: " << v.getVal(60000) << std::endl;
	std::cout << "Index: 60,000" << std::endl;
	std::cout << "Size:  " << v.getSize() << std::endl;
    std::cout << std::endl;
    
    //wall clock time
    auto t_end1 = std::chrono::high_resolution_clock::now();
    //get total time
    auto my_time = std::chrono::duration<double, std::milli>(t_end1 - t_start1).count();
	//free memory 
    v._free();
    
    /////////////////////////////////////////////////////////////////
    ///////////////////Now trying with std::vector///////////////////
    /////////////////////////////////////////////////////////////////
    
    //vector with 100 ints each with value 0
    std::vector<int> vec(100, 0);
	//iterator
    std::vector<int>::iterator it;
    it = vec.begin();

	std::cout << "##############\n" << std::endl;
	std::cout << "std::vector: " << std::endl << std::endl;
    //wall clock time
    auto t_start2 = std::chrono::high_resolution_clock::now();
    
    //put the value 20 in the index 30
    vec.insert(it + 30, 20);
    //display value, index, and size 
    std::cout << "Value: " << vec.at(30) << std::endl;
	std::cout << "Index: 30" << std::endl;
	std::cout << "Size:  " << vec.size() << std::endl;
    std::cout << std::endl;

    //recreate iterator
    it = vec.begin();
    //put the value 40 in the index 100
    vec.insert(it + 100, 40);
    //display value, index, and size 
    std::cout << "Value: " << vec.at(100) << std::endl;
	std::cout << "Index: 100" << std::endl;
	std::cout << "Size:  " << vec.size() << std::endl;
    std::cout << std::endl;
    
    //resize so vector has enough room
    vec.resize(60000);
    //recreate iterator
    it = vec.begin();
    //put the value 812 in the index 60,000
    vec.insert(it + 60000, 812);
    //display value, index, and size 
    std::cout << "Value: " << vec.at(60000) << std::endl;
	std::cout << "Index: 60,000" << std::endl;
	std::cout << "Size:  " << vec.size() << std::endl;
    std::cout << std::endl;
    
    //Inserting will increase the size of the vector by 1 which is why the vector has sizes
    //101, 102, and 60,001
    
    //wall clock time
    auto t_end2 = std::chrono::high_resolution_clock::now();
    //get total time
    auto vec_time = std::chrono::duration<double, std::milli>(t_end2 - t_start2).count();

	std::cout << "##############\n" << std::endl;
    std::cout << "My time: " << my_time << " ms" << std::endl;
    std::cout << "std::vector time: " << vec_time << " ms" << std::endl;
    
    return 0;
}

