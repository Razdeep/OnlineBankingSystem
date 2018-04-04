// This is a debug class for creation of database file
// This code is just to add data to the binary file
#include<iostream>
#include<fstream>
#include"customer.h"
using namespace std;
int main()
{
    fstream fout("customer.txt",ios::binary|ios::out|ios::trunc);
    TimeStamp ts(21,7,98);
    // Customer customer(1,"Rajdeep","Kolkata",9674810029,TimeStamp(21,7,98),(float)25000);
    // Customer customer(1,new string("Rajdeep"),new string("Kolkata"),(long int)9674810029,new TimeStamp(21,7,98),(float)25000.0);
    int id=1;
    // string name="Rajdeeep";
    // string address="Kolkata";
    char *name="Rajdeep";
    char *address="Kolkata";
    long int phone= 9674810029;
    // TimeStamp *ts=new TimeStamp(21,7,98);
    float bal=25000;
    Customer customer(id,name,address,phone,ts,bal);
    fout.write((char*)&customer,sizeof(customer));
    fout.close();
    return 0;
}