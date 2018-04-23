// This file is for testing transaction module
#include<iostream>
#include"utility.h"
#include"txn.h"
int main(int argc, char *argv[])
{
    TimeStamp ts(21,07,2001);
    Customer cust(99,"Hinata","Hyuga Castle",404,ts,"root",10000);

    Txn *txn=new Txn(101,ts,cust,2000,'d');
    txn->printTxn();
    delete txn;
    return EXIT_SUCCESS;
}