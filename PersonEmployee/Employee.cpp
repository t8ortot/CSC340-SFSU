/**
* An employee class that inherits attributes from the person class as well as implements its own attributes such as salary, work email, salary change rate, and amount of salary changes.
* @author James Clark
*/
#include "Employee.h"

/**
* Consutructor
*/
Employee::Employee() {

    // initializes salary, salary changes, work email, and change rates to blank values.
    this->salary = 0.0;
    this->cnt_sal_changes = 10;
    this->work_email = "work@";
    this->sal_change_rates = new double [this->cnt_sal_changes];

    for(int i = 0; i < this->cnt_sal_changes; i++){
        this->sal_change_rates[i] = 0.0;
    }
}

/**
* Destructor
*/
Employee::~Employee(){

    // deletes the salaray change rates array
    if(this->sal_change_rates != nullptr){
        delete [] sal_change_rates;
        this->sal_change_rates = nullptr;
    }

    // resets salary, change count, and work email to blank values
    this->salary = 0.0;
    this->cnt_sal_changes = 10;
    this->work_email = "work@";
}

/**
* Copy constructor
* @param clone The Employee object to clone
*/
Employee::Employee( const Employee& clone){

    //copy salaray change count, and work email
    this->salary = clone.salary;
    this->cnt_sal_changes = clone.cnt_sal_changes;
    this->work_email = clone.work_email;

    // copy salary change rates
    this->sal_change_rates = new double [this-> cnt_sal_changes];
    for(int i = 0; i < this->cnt_sal_changes; i++){
        this->sal_change_rates[i] = clone.sal_change_rates[i];
    }
}

/**
* Assignment operator overload
* @param rhs Employee object to be copied
*/
Employee& Employee::operator=(const Employee& rhs ){

    //copy salay, change count, and work email
    this->salary = rhs.salary;
    this->cnt_sal_changes = rhs.cnt_sal_changes;
    this->work_email = rhs.work_email;

    // delete existing change rate array
    if(this->sal_change_rates != nullptr){
        delete [] sal_change_rates;
        this->sal_change_rates = nullptr;
    }

    // initialize and copy salary change rate array
    this->sal_change_rates = new double [this->cnt_sal_changes];
    for(int i = 0; i < cnt_sal_changes; i++){
        this->sal_change_rates[i] = rhs.sal_change_rates[i];
    }

    return *this;
}

/**
* Getter for the salary change rate at index i
* @param i index to retrieve value from
*/
double Employee::getChangeRate( int i) const{
    return this->sal_change_rates[i];
}

/**
* Getter for the employee's work email
*/
string Employee::getEmail() const{
    return this->work_email;
}

/**
* Setter for the employee's work email
* @param new_email new email for employee
*/
void Employee::setEmail(string new_email) {
    this->work_email = new_email;
}

/**
* Returns type of object
* Used for inheritance exercise
*/
string Employee::getTypeOfObj() const {
    return "Employee";
}

/**
* Creates a mixed array of Person and Employee objects
* @param arrayPersonEmp double pointer for array
* @param numPersons number of person objects to initialize
* @param numEmployees number of employee object to initialize
*/
void mixedArray( Person** &arrayPersonEmp, int numPersons, int numEmployees){

    // initialize array
    arrayPersonEmp = new Person* [numPersons+numEmployees];

    // add Person objects
    for(int i = 0; i < numPersons; i++){
        arrayPersonEmp[i] = new Person();
        arrayPersonEmp[i]->setEmail("personal@gmail.com");
    }

    // add Employee objects
    for(int i = numPersons; i < numPersons+numEmployees; i++){
        arrayPersonEmp[i] = new Employee();
        arrayPersonEmp[i]->setEmail("work@gmail.com");
    }
}

/**
* Deletes the mixed array
* @param arrayPersonEmp double pointer for array location
* @param size length of array
*/
void deleteMixedArray(Person** &arrayPersonEmp, int size ){

    // delete all objects in array
    if(arrayPersonEmp != nullptr) {
        for (int i = 0; i < size; i++) {
            delete arrayPersonEmp[i];
        }

        // delete array
        delete [] arrayPersonEmp;

    }


}
