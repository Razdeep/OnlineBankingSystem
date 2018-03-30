#include<iostream>
#include"person.h"
#ifndef __CUSTOMER_H
#define __CUSTOMER_H
class Customer:public Person{
    private:
    float balance;

    protected:

    public:
    Customer(int ID,std::string name,std::string address,long int phone, TimeStamp dob,float balance):
    Person(ID,name,address,phone,dob),balance(balance){};

    // void setValues();

};
#endif