//
// Created by Jimmy on 11/24/2017.
//
#include <iostream>
#include "ListADT.h"
#include "VectorADT.h"

using namespace std;

int main(){

    cout << "***** Vector Tests *****" << endl;
    
    VectorADT vTest;
    
    for(int i=0; i< 11; i++){
        vTest.push_back(i);
    }
    vTest.resize(11);

    VectorADT vTest2(vTest);

    vTest+vTest2;
    cout << "Capacity: " << vTest.curr_capacity() << endl;
    cout << "Length: " << vTest.length() << endl;

    for (int i = 0; i < vTest.length(); i++){
        cout << "vTest[" << i << "]: " << vTest[i] << endl;
    }


    cout << "***** List Tests *****" << endl;

    ListADT lTest;
    lTest.push_back(3);
    lTest.push_back(4);

    ListADT lTest2(lTest);
    lTest2.push_back(5);

    cout << "Original: " << lTest << endl;
    cout << "Copy with 5 added: " << lTest2 << endl;
    cout << "Length of original: " << lTest.length() << endl;
    cout << "Length of copy: " << lTest2.length() << endl;
    return 0;
}