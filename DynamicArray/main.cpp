/**
* A program that creates an array, assigns values to it, and displays final output.
* @author James Clark
*/
#include <iostream>
#include "dynamicArray.h"

using namespace std;

/**
* main() for program. Creates a large array and then shrinks it. Outputs final contents of pointer.
*/
int main() {
    // pointer to integer array
    int *Ptr = new int[4];
    //original size of array
    int size = 15;
    // new size of array
    int newSize = 6;

    //connstructs an array that the pointer with point to
    array_constructor(Ptr, size);

    // resizes the array to the new size.
    array_resize(Ptr, size, newSize);

    //print contents of entire array
    for(int i = 0; i < newSize; i++){
        cout << Ptr[i] << endl;
        if (i == newSize-1){
            cout<< "_________________" << endl;
        }
    }





    return 0;
}