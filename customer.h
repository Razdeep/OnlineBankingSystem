#include<iostream>
#include"person.h"
#ifndef __CUSTOMER_H
#define __CUSTOMER_H
class Customer:public Person{
    private:
    float balance;

    protected:

    public:
    Customer():Person(){}
    Customer(int ID,char *name,char *address,long int phone, TimeStamp dob,float balance):
    Person(ID,name,address,phone,dob),balance(balance){};
    
    void showDetails() const;
    // void setValues();

};
#endif