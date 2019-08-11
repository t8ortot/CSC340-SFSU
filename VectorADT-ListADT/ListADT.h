/**
* ListADT header file
* @author James Clark
*/

#ifndef A13_LISTADT_H
#define A13_LISTADT_H

#include <iostream>
class ListADT {
public:
    //Default constructor
    ListADT();

    //big-3
    //destructor
    ~ListADT();
    //copy constructor
    ListADT (const ListADT &clone);
    //overload assignment operator
    ListADT& operator= ( const ListADT& rhs );

    //inserts value val into end of list
    void push_back(int val);
    //inserts value val into front of list
    void push_front(int val);

    //deletes last number from list
    void pop_back();
    //deletes first number in list
    void pop_front();

    //returns value of i-th node
    int operator[] (int i);

    //prints all values in list
    friend std::ostream&  operator<<(std::ostream& outStrm, const ListADT& rhs);

    //returns size
    int length() const;


private:
    class Node{
    public:
        Node():value(0), next(nullptr){};
        explicit Node(int val):value(val), next(nullptr){};

        //the value the node holds
        int value; 
        //the next node in the list
        Node* next; 
    };

    //points to first node in list
    Node* head =0;
    //number of nodes in list
    int size =0; 

};
#endif //A13_LISTADT_H
