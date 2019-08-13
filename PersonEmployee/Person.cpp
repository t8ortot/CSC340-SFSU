/**
* A person class that has an SSN, name, personal email address, and a list of places they have been to.
* @author James Clark
*/
#include "Person.h"

/**
* Constructor
*/
Person::Person(){
    // initializes a blank person object
    this->SSN = 0;
    this->name = "na";
    this->personalEmail = "personal@";
    this->cntPlaces = 10;
    this->placesVisited = new string[this->cntPlaces];
    for(int i = 0; i < this->cntPlaces; i++){
        this->placesVisited[i] = "unknown";
    }
}

/**
* Deconstructs object
*/
Person::~Person() {

    // if placesVisited has not already been deleted
    if (this->placesVisited != nullptr){
        // free the allocated space
        delete [] placesVisited;
        // assign pointer to null
        this->placesVisited = nullptr;
    }

    // re-initialize to blank person object
    this->SSN = 0;
    this->name = "na";
    this->personalEmail = "personal@";
    this->cntPlaces = 10;

}

/**
* Assignment operator overload
* @param rhs Person object to be copied to this
*/
Person& Person::operator=(const Person& rhs ){

    // copy information from rhs
    this->SSN = rhs.SSN;
    this->name = rhs.name;
    this->personalEmail = rhs.personalEmail;
    this->cntPlaces = rhs.cntPlaces;

    //if this is not empty, delete existing data
    if (this->placesVisited != nullptr){
        delete [] placesVisited;
        this->placesVisited = nullptr;
    }

    // create new string array
    this->placesVisited = new string[this->cntPlaces];

    // copy places
    for(int i = 0; i < cntPlaces; i++){
        this->placesVisited[i] = rhs.placesVisited[i];
    }

    return *this;
}

/**
* Copy constructor
* @param clone Person object to clone
*/
Person::Person(const Person &clone ){

    // copy contents of clone 
    this->SSN = clone.SSN;
    this->name = clone.name;
    this->personalEmail = clone.personalEmail;
    this->cntPlaces = clone.cntPlaces;
    this->placesVisited = new string[this->cntPlaces];

    //copy places
    for(int i = 0; i < cntPlaces; i++){
        this->placesVisited[i] = clone.placesVisited[i];
    }
}

/**
* Returns the place vistsed store in the i-th index
* @param i index of place to return
*/
string Person::getPlace(int i) const{
    return this->placesVisited[i];
}

/**
* Returns the person's personal email
*/
string Person::getEmail() const{
    return this->personalEmail;
}

/**
* Setter for personal email
* @param new_email new personal email
*/
void Person::setEmail( string new_email){
    this->personalEmail = new_email;
}

/**
* Returns the type of object this is
* Used for an inheritance example.
*/
string Person::getTypeOfObj() const{

    return "Person";
}