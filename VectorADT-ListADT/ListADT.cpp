/**
* A custom built List class designed to perform the same features and functions as std::list
* @author James Clark
*/

#include "ListADT.h"

/**
* Constructor
*/
ListADT::ListADT() {
    // starting size 0
    this->size = 0;
    // no head assigned
    this->head = nullptr;
}

/**
* Deconstructor
*/
ListADT::~ListADT() {

    // current node
    Node *curr = this->head;

    //if the node is not null
    while(curr != nullptr) {
        // store next node position
        Node *temp = curr->next;
        // delete current node
        delete curr;
        // make current to next node
        curr = temp;
    }

    // assign head as null
    this->head = nullptr;
    // size is now 0
    this->size = 0;
}

/**
* Copy constructor
* @param clone The ListADT object to clone
*/
ListADT::ListADT(const ListADT &clone) {

    // get clone's head
    auto *tempN = clone.head;

    //if the clone size is greater than 0
    if(clone.size > 0) {
        // while the list is not empty
        do {
            // push node into this list
            this->push_back(tempN->value);
            // step to next node
            tempN = tempN->next;
        } while(tempN != nullptr);
    }
}

/**
* Overloaded assignment operator to perform copy
* @param rhs The ListADT object to copy to this object
*/
ListADT& ListADT::operator=(const ListADT &rhs) {

    // deconstructs this object
    this->~ListADT();

    // track head node
    Node* curr = rhs.head;
    // copy size
    this->size = rhs.size;

    // push back nodes of rhs to this object
    while(curr != nullptr){
        this->push_back(curr->value);
        curr = curr->next;
    }

    // return this object
    return *this;
}

/**
* Adds a value to the end of the list
* @param val value to be added to list
*/
void ListADT::push_back(int val) {
    // initialize new node
    auto *newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;

    //if size is 0, make new value the head
    if(this->size == 0){
        this->head = newNode;

    // otherwise connect node to the last node
    } else {
        Node *temp = this->head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // increment size
    this->size++;
}

/**
* Adds value to front of list
* @param val Value to be added to front of list
*/
void ListADT::push_front(int val) {
    // initialize new npde
    auto *newNode = new Node;
    newNode->value = val;
    // assign the current head as next node
    newNode->next = this->head;

    // make new node head
    this->head = newNode;
    // increment size
    this->size++;
}

/**
* Removes the node from the back of the list
*/
void ListADT::pop_back() {
    // track head to find second to last node
    Node *temp1 = this->head;
    while (temp1->next->next) {
        temp1 = temp1->next;
    }

    // copy second to last node
    Node *temp2 = temp1;
    // step to last node
    temp1 = temp1->next;
    //delete last node
    delete temp1;
    // assign new last node with null tail
    temp2->next = nullptr;
    //decrement size
    this->size--;
}

/**
* Removes front node from list
*/
void ListADT::pop_front() {
    // if a head exists
    if(this->head) {
        // track current head
        Node *temp = this->head;
        // assign new head
        head = this->head->next;

        // delete old head
        delete temp;
        //decrement size
        this->size--;
    }
}

/**
* Returns the i-th node in the list
* @param i index to return
* @return value at i-th position
*/
int ListADT::operator[](int i) {

    // value to return
    int value = 0;

    // if i is less than the size
    if (i < size) {
        // track head to incrment through list to i-th element
        Node *temp = this->head;
        for (int n = 0; n < i && temp; n++) {
            temp = temp->next;
        }

        //if value is greater than 0
        if (temp) {
            value = temp->value;
        }
    }
    return value;
}

/**
* Overloads the output stream operator
* @param outStrm output stream
* @param rhs this object
*/
std::ostream& operator<<(std::ostream& outStrm, const ListADT& rhs){

    //initialize temp to track head
    auto temp = rhs.head;
    // output head value
    outStrm << temp->value;
    // continue to output foloowing values until end of list
    while(temp->next){
        temp = temp->next;
        outStrm << ", " << temp->value;
    }
    return outStrm;
}

/**
* Returns the length of this list
*/
int ListADT::length() const {
    return this->size;
}