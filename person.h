#include<iostream>
#ifndef __PERSON_H
#define __PERSON_H
#include"timestamp.h"
class Person{
    private:

    protected:
    int ID;
    std::string name;
    std::string address;
    long int phone;
    TimeStamp dob;
    
    public:
    Person(){}
    Person(int ID,std::string name,std::string address,long int phone, TimeStamp dob):
    ID(ID),name(name),address(address),phone(phone),dob(dob){};

    void getBasicDetails() const; //@TODO
    int getID() const;
    
};
#endif