/**
* @author James Clark
*/

#ifndef DYNAMICARRAY_DYNAMICARRAY_H
#define DYNAMICARRAY_DYNAMICARRAY_H

int * array_constructor(int *  &intPtr, int &size );
int * array_resize(int * &intPtr, int& currSize, int& newSize);
void array_destructor(int * &intPtr);
void array_set(int* &intPtr, int &size);
void mysort( int* &intPtr, int size, bool (* comp)(int&, int&) );
bool my_less_equal(int& x, int & y);   //return true if x<=y, false otherwise.
bool my_greater_equal(int& x, int & y ); //return true if x>=y, false otherwise.

#endif //DYNAMICARRAY_DYNAMICARRAY_H
