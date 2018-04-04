#include<iostream>
#ifndef __PERSON_H
#define __PERSON_H
#include"timestamp.h"
#include<cstring>
class Person{
    private:

    protected:
    int ID;
    // std::string name;
    // std::string address;
    char name[30];
    char address[30];
    long int phone;
    TimeStamp dob;
    
    public:
    Person(){}
    // Person(int ID,std::string name,std::string address,long int phone, TimeStamp dob):
    // ID(ID),phone(phone),dob(dob),name(name),address(address){};
    Person(int ID,char* name,char* address,long int phone, TimeStamp dob):
        ID(ID),phone(phone),dob(dob){
        strcpy(this->name,name);
        strcpy(this->address,address);
    };

    void printBasicDetails() const; //@TODO
    int getID() const;
    
};
#endif