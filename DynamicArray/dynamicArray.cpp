/**
* Functions that can create, mutate, and destroy a synamic array stored in memory.
* @author James Clark
*/

//to use time(0)
#include <ctime> 
//to use rand
#include <cstdlib>
#include <new>
#include <iostream>

using namespace std;

/**
* A function for determining if a value is less than or equal to another
* @param x main value
* @param y value to compare to
*/
bool my_less_equal(int &x, int &y) {
    // return true if x is less than or equal to y
    if (x <= y) {
        return true;
    }
    
    return false;
}

/**
* A function for determining if a value is greater than or equal to another
* @param x main value
* @param y value to compare to
*/
bool my_greater_equal(int &x, int &y) {
    // return true if x is greater than or equal to y
    if (x >= y) {
        return true;
    }
    
    return false;
}

/**
* Constructs an array of a certain size. A pointer is set to point towards the new array.
* @param intPtr pointer to be assigned to the new array
* @param size size of the new array
*/
void array_constructor(int *&intPtr, int &size) {
    // validation
    if(size > 0) {
        // if pointer contains something, empty it.
        if (!intPtr) {
            delete intPtr;
            intPtr = nullptr;
        }

        try {
            // allocate memory for an array of size "size"
            intPtr = new int[size];
        // error
        } catch (bad_alloc &e) {
            cerr << "bad_alloc caught:" << e.what();
            exit(-1);
        }

        //initialize each value of array to square values
        for (int i = 0; i < size; i++) {
            intPtr[i] = i * i;
        }
    }
}

/**
* Resizes an array to a new size while keeping its original contents.
* @param intPtr pointer to be assigned to newly sized array
* @param currSize current size of the array
* @param newSize nnew size of the array
*/
void array_resize(int *&intPtr, int &currSize, int &newSize) {
    // if new size is 0, create a null pointer
    if (newSize == 0){
        delete [] intPtr;
        intPtr = nullptr;
    }

    // if the array sizes are greater than zero and not equal
    if (currSize > 0 && newSize > 0 && currSize != newSize) {
        //if the new size will be larger
        if (currSize < newSize) {
            // create the larger array
            int *temp = new int[newSize];

            // copy the original array and then continue to fill contents with more squares
            for (int i = 0; i < newSize; i++) {
                if (i < currSize) {
                    temp[i] = intPtr[i];
                } else {
                    temp[i] = i * i;
                }
            }

            //delete old pointer contents
            delete [] intPtr;
            //allocate space for new array
            intPtr = new int[newSize];
            //copy temp to pointer
            for (int i = 0; i < newSize; i++){
                intPtr[i] = temp[i];
            }
            //delete temp
            delete [] temp;

        // if the new array will be smaller
        } else if (currSize > newSize) {
            // create smaller array
            int *temp = new int[newSize];
            // trim the end of the array off
            for (int i = 0; i < newSize; i++) {
                    temp[i] = intPtr[i];

            }
            //delete old contents
            delete [] intPtr;

            //create new array
            intPtr = new int[newSize];
            //copy temp
            for (int i = 0; i < newSize; i++){
                intPtr[i] = temp[i];
            }
            //delete temp
            delete [] temp;
        }
    }
}

/**
* Deconstructs contents of array.
* @param intPtr pointer to be deconstructed
*/
void array_destructor(int *&intPtr) {
    // if not already null
    if(intPtr!= nullptr) {
        // delete contents
        delete[] intPtr;
        // assign null
        intPtr = nullptr;
    }
}

/**
* A function that sets contents of array to random values.
* @param intPtr pointer to array
* @param size current size of array
*/
void array_set(int *&intPtr, int &size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        intPtr[i] = rand();
    }
}

/**
* Sorts the array.
* @param intPtr pointer to array to be sorted
* @param size current size of array
* @param comp function to be used for sorting
*/
void mysort(int *&intPtr, int size, bool (*comp)(int &, int &)) {

    int i, key, j;
    // sort in descending order
    if ((*comp) == my_less_equal ) {
        for (i = 1; i < size; i++) {
            key = intPtr[i];
            j = i - 1;
            while (j >= 0 && intPtr[j] > key) {
                intPtr[j + 1] = intPtr[j];
                j = j - 1;
            }
            intPtr[j + 1] = key;
        }
    }
    // sort in ascending order
    else if ((*comp) == my_greater_equal) {
        for (i = 1; i < size; i++) {
            key = intPtr[i];
            j = i - 1;

            while (j >= 0 && intPtr[j] < key) {
                intPtr[j + 1] = intPtr[j];
                j = j - 1;
            }
            intPtr[j + 1] = key;
        }
    }
}


