#include<iostream>
#ifndef __PERSON_H
#define __PERSON_H
class Person{
    protected:
    std::string name[30];
    int dob;
    public:
    void getBasicDetails();
};
#endif