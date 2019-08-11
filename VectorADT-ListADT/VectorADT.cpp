/**
* A custom built Vector class designed to perform the same features and functions as std::vector
* @author James Clark
*/

#include "VectorADT.h"

/**
* Default constructor
*/
VectorADT::VectorADT() {

    //how many items are in the vector
    this->size = 0;
    // max capacity of vector
    this->capacity = 10;

    try {
        // ceate new array
        this->array = new double[10];
    } catch (std::bad_alloc &e) {
        std::cerr << "bad_alloc caught:" << e.what();
        exit(-1);
    }

    //initialize all values to 0
    for (int i = 0; i <= 9; i++) {
        this->array[i] = 0.00;
    }
}

/**
* Deconstructor
*/
VectorADT::~VectorADT() {

    //if it has not already been made null
    if (this->array != nullptr) {
        delete this->array;
        this->array = nullptr;
    }
    //size is 0
    this->size = 0;
    //capacity is 0
    this->capacity = 0;
}

/**
* Copy constructor
* @param clone VectorADT object to be cloned
*/
VectorADT::VectorADT(const VectorADT &clone) {

    //copies size and capacity
    this->size = clone.size;
    this->capacity = clone.capacity;

    // creates an array that is the same size as the capacity of the clone
    try {
        this->array = new double[this->capacity];
    } catch (std::bad_alloc &e) {
        std::cerr << "bad_alloc caught:" << e.what();
        exit(-1);
    }

    // copies contents of array
    for (int i = 0; i < this->capacity; i++) {
        this->array[i] = clone.array[i];
    }
}

/**
* Assignment operator overload
* @param rhs VectorADT object to be copied to this object
*/
VectorADT &VectorADT::operator=(const VectorADT &rhs) {
    //deconstruct this object
    this->~VectorADT();

    //resize this object
    this->resize(rhs.size);

    //copy size and capacity
    this->size = rhs.size;
    this->capacity = rhs.capacity;

    //copy contents
    for (int i = 0; i < this->size; i++) {
        this->array[i] = rhs.array[i];
    }

    //return this object
    return *this;
}

/**
* Insert a value to the end of the array
* @param val The value to insert
*/
void VectorADT::push_back(double val) {

    // if the size is less than the capacity
    if (size < capacity) {
        // add value to end
        this->array[size] = val;
        // increment size
        this->size++;
    // if the size is greater than the capacity
    } else if (size >= capacity) {
        //resize array for more capacity
        this->resize(size);
        // insert value to end
        array[size] = val;
        // increment size
        size++;
    }
}

/**
* Resizes the array to increase its capacity for more values.
* @param newSize the size of the array
*/
void VectorADT::resize(int newSize) {
    double *tempArray = nullptr;

    // if the new size is less than the current capacity
    if (newSize < this->curr_capacity()) {
        
        // temporary holder for capacity
        int tcap = this->capacity;

        //make a new array of the current capacity size
        try {
            tempArray = new double[this->curr_capacity()];
        } catch (std::bad_alloc &e) {
            std::cerr << "bad_alloc caught:" << e.what();
            exit(-1);
        }

        // copy contents. If values have not been assigned, initialize them as 0.0
        for (int i = 0; i < this->capacity; i++) {
            if (i < newSize) {
                tempArray[i] = this->array[i];
            } else {
                tempArray[i] = 0.00;
            }
        }

        //decontruct this object
        this->~VectorADT();
        // assign new capacity
        this->capacity = tcap;

    // if newSize is greater than the current capacity
    } else {
        //create a temporary array twice as large as the new size
        try {
            tempArray = new double[newSize * 2];
        } catch (std::bad_alloc &e) {
            std::cerr << "bad_alloc caught:" << e.what();
            exit(-1);
        }

        // copy contents. if value has not been assigned, initialize with 0.0
        for (int i = 0; i < newSize * 2; i++) {
            if (i < this->size) {
                tempArray[i] = this->array[i];
            } else {
                tempArray[i] = 0.00;
            }
        }

        // deconstruct this object
        this->~VectorADT();
        //set capacity to twice the newSize
        this->capacity = newSize * 2;
    }

    // allocate memory for an array that is the size of the new capacity value
    try {
        this->array = new double[this->capacity];
    } catch (std::bad_alloc &e) {
        std::cerr << "bad_alloc caught:" << e.what();
        exit(-1);
    }

    //copy contents
    for (int i = 0; i < this->capacity; i++) {
        this->push_back(tempArray[i]);
    }

    // set size to newSize
    this->size = newSize;
}

/**
* Removes a value from the last index of the array
*/
void VectorADT::pop_back() {
    //if there is a value in the array
    if (size > 0) {
        // reassign to 0.0
        this->array[size - 1] = 0.00;
        // decremnts size
        this->size--;
    }
}

/**
* Returns the value at a specific index
* @param i index of value to return
*/
double VectorADT::operator[](int i) {
    return this->array[i];
}

/**
* Overloads the addition operator. ONLY WORKS IF ARRAY SIZES ARE EQUAL
* @param rhs The Vecotr ADT value to be added to this array
*/
const VectorADT &VectorADT::operator+(const VectorADT &rhs) {

    //if array sizes are equal
    if (this->size == rhs.size) {
        // the sum array
        double sum [this->size];
        // temporary size holder
        int tempS = this->size;
        // temporary capacity holder
        int tempC = this->capacity;

        // adds all the contents from both arrays together
        for (int i = 0; i < tempS; i++) {
            sum[i] = this->array[i] + rhs.array[i];
        }

        // deconstruct this array
        this->~VectorADT();
        // allocate memory for an array with size of capacity
        this->array = new double [tempC];
        // assign new capactiy
        this->capacity = tempC;

        // add sums to new array, if value has not been assigned, initialize to 0.0
        for(int i = 0; i < tempC; i++){
            if(i < tempS){
                this->push_back(sum[i]);
            }else{
                this->push_back(0.00);
            }
        }
        // assign new size
        this->size = tempS;
    }

    return *this;
}

/**
* output stream operator overload
* @param outStrm output stream
* @param object to output
*/
std::ostream &operator<<(std::ostream &outStrm, const VectorADT &rhs) {
    // output all contents of array
    outStrm << rhs.array[0];
    for (int i = 1; i < rhs.size; i++) {
        outStrm << ", " << rhs.array[i];
    }
    return outStrm;
}

/**
* Returns current number of values in the array
*/
int VectorADT::length() const {
    return this->size;
}

/**
* Returns current capacity of this array
*/
int VectorADT::curr_capacity() const {
    return this->capacity;
}