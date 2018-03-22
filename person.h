#include<iostream>
#ifndef __PERSON_H
#define __PERSON_H
class Person{
    private:

    protected:
    std::string name[30];
    int dob;
    
    public:
    void getBasicDetails(); //@TODO
};
#endif