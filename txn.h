#ifndef __TXN_H
#define __TXN_H
#include"timestamp.h"
#include"customer.h"
class Txn{
    int id;
    TimeStamp ts;
    Customer cust;
    float amount;
    char type;
    public:
    Txn(); //@TODO
    void printTxn() const;//@TODO
};
#endif