#ifndef __TXN_H
#define __TXN_H
#include"timestamp.h"
class Txn{
    int id;
    TimeStamp ts;
    float amount;
    char type;
    public:
    Txn(); //@TODO
    void printTxn();//@TODO
};
#endif