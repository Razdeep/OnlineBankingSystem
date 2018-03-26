#include<iostream>
#include"person.h"
#ifndef __CUSTOMER_H
#define __CUSTOMER_H
class Customer:public Person{
    private:
    float balance;

    protected:

    public:
    Customer();
    void setValues();

};
#endif