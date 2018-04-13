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
    char pass[30];
    
    public:
    Person(){}
    // Person(int ID,std::string name,std::string address,long int phone, TimeStamp dob):
    // ID(ID),phone(phone),dob(dob),name(name),address(address){};
    Person(int ID,const char* name,const char* address,long int phone, TimeStamp dob,const char* pass):
        ID(ID),phone(phone),dob(dob){
        strcpy(this->name,name);
        strcpy(this->address,address);
        strcpy(this->pass,pass);
    };
    virtual void showDetails() const=0;
    //MAKING THIS CLASS AN ABSTRACT CLASS
    
};
#endif