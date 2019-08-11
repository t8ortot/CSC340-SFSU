# Vector and List ADT
Implementations to create custom Vector and List object that are designed to perform some of the same features and functions the actual std::vector and std::list objects can peform.

Learned destructors, copy constructors, overload operators, list traversal.

How to run (assuming in VectorADT-ListADT directory):
- g++ -std=c++17 testVectorList.cpp ListADT.cpp VectorADT.cpp
- ./a.out

How to use:
After running the program, an output will appear with some tests. The first tests are for the VectorADT class and the second half of the tests are for the ListADT class. A walkthrough of the tests is:
- Vector Tests
	- Create a vector, whose size starts as zero and capacity at 10
	- Add more objects than the capacity can hold to test automatic resizing
	- Copies the vector to another and then adds the copy to the original using the + operator
	- Outputs the final size, capacity and contents of the vector
- List tests
	- Create a list with 2 values
	- Create a copy of the list and add a 5 to it.
	- Output the lengths of the lists