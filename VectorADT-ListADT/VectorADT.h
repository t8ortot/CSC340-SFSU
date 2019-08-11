/**
* VectorADT header file
* @author James Clark
*/

#ifndef A13_VECTORADT_H
#define A13_VECTORADT_H

#include <iostream>
#include <string>
#include <new>

class VectorADT{
public:
    //default constructor
    VectorADT();

    /*Big-3*/
    //destructor
    ~VectorADT();
    //copy constructor
    VectorADT (const VectorADT &clone);
    //overload assignment operator
    VectorADT& operator= ( const VectorADT& rhs );

    //inserts val
    void push_back(double val);

    //resize to newSize
    void resize(int newSize);

    //deletes last position in array, decreases container by 1
    void pop_back();

    //returns array[i]
    double operator[] (int i);

    //add two VectorADTs with same size and create new VectorADT
    const VectorADT& operator+ (const VectorADT& rhs);

    //prints all elements in the VectorADT
    friend std::ostream&  operator<<(std::ostream& outStrm, const VectorADT& rhs);

    //returns size of array
    int length() const;

    //returns the capacity of the array
    int curr_capacity() const;

private:
    //container of doubles
    double * array; 
    //the number of doubles stored in array
    int size = 0; 
    //the maximum number of doubles that can be stored in array
    int capacity = 0; 
};
#endif //A13_VECTORADT_H
