#include<iostream>
#include"person.h"
#ifndef __CUSTOMER_H
#define __CUSTOMER_H
class Customer:public Person{
    private:
    float balance;

    protected:

    public:
    Customer(char groupID,int ID,std::string name,std::string address,long int phone, TimeStamp dob,float balance):
    Person(groupID,ID,name,address,phone,dob){};

    // void setValues();

};
#endif