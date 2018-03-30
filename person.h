#include<iostream>
#ifndef __PERSON_H
#define __PERSON_H
#include"timestamp.h"
class Person{
    private:

    protected:
    char groupID;
    int ID;
    std::string name;
    std::string address;
    long int phone;
    TimeStamp dob;
    
    public:
    Person(char groupID,int ID,std::string name,std::string address,long int phone, TimeStamp dob):
    groupID(groupID),name(name),address(address),phone(phone),dob(dob){};

    void getBasicDetails() const; //@TODO
    int getID() const;
    char getGroupID() const;
    std::string getCombinedID() const; //@TODO GROUPID+ID
};
#endif