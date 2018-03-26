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
    void getBasicDetails(); //@TODO
    int getID();
    char getGroupID();
    std::string getCombinedID(); //@TODO GROUPID+ID
};
#endif