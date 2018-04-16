/*  Copyright (c) Rajdeep Roy Chowdhury 2018 <rrajdeeproychowdhury@gmail.com>
*   This file is part of CSE202 Online Banking Management System Project
*
*   Permission is hereby granted, free of charge, to any person obtaining a copy of 
*   this software and associated documentation files (the "Software"), to deal in the Software 
*   without restriction, including without limitation the rights to use, copy, modify, merge, 
*   publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons 
*   to whom the Software is furnished to do so, subject to the following conditions:
*   The above copyright notice and this permission notice shall be included in all copies or 
*   substantial portions of the Software.
*
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
*   BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
*   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
*   DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
*   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/

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
    // std::string pass;
    
    public:
    Person(){}
    // Person(int ID,std::string name,std::string address,long int phone, TimeStamp dob,std::string pass):
    // ID(ID),phone(phone),dob(dob),name(name),address(address),pass(pass){};
    Person(int ID,const char* name,const char* address,long int phone, TimeStamp dob,const char* pass):
        ID(ID),phone(phone),dob(dob){
        strcpy(this->name,name);
        strcpy(this->address,address);
        strcpy(this->pass,pass);
    };
    //COPY CONSTRUCTOR MUST BE CREATED INORDER TO MAKE VECTOR WORK
    Person(const Person&);

    virtual void showDetails() const=0;
    //MAKING THIS CLASS AN ABSTRACT CLASS

    //BUNCH OF GETTERS
    int getID() const;
    const char* getName() const;
    const char* getAddress() const;
    long int getPhone() const;
    TimeStamp getDob() const;
    const char* getPass() const;
    void setPass(const char*);
};
#endif