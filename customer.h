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
    // Customer(int ID,std::string name,std::string address,long int phone, TimeStamp dob,float balance):
    // Person(ID,name,address,phone,dob),balance(balance){};
    Customer(int ID,const char* name,const char* address,long int phone, TimeStamp dob,const char* pass,float balance):
    Person(ID,name,address,phone,dob,pass),balance(balance){};
    
    void showDetails() const;
    // void setValues();

};
#endif