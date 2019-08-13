/**
* Employee header file
*/ 

#ifndef A14_EMPLOYEE_H
#define A14_EMPLOYEE_H

#include "Person.h"

class Employee:public Person
{
private:
    string work_email;
    double salary;
    double *sal_change_rates;
    int    cnt_sal_changes;
public:
    virtual ~Employee();
    Employee(); //0.0->salary, 10->cnt_sal_changes, "work@"->work_email, sal_change_rates: allocate memory to hold 10 doubles, each of which has an initial value of 0.0
    Employee( const Employee& clone);
    Employee& operator=(const Employee& rhs );

    double getChangeRate( int i) const;////return the i-th rate in the sal_change_rates array if i is valid; otherwise return -1.00

    virtual string getEmail() const; //return work_email
    virtual void setEmail( string new_email); //new_email-->work_email
    virtual string getTypeOfObj() const; //return "Employee"
};

void mixedArray( Person** &arrayPersonEmp, int numPersons, int numEmployees);

void deleteMixedArray(Person** &arrayPersonEmp, int size );

#endif //A14_EMPLOYEE_H
