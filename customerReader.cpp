// This is a debug class for creation of database file
// This code is just to read data from the binary file
#include<iostream>
#include<fstream>
#include"customer.h"
using namespace std;
int main()
{
    fstream fin("customer.txt",ios::binary|ios::in);
    // TimeStamp ts(21,7,98);
    // Customer customer(1,"Rajdeep","Kolkata",9674810029,TimeStamp(21,7,98),(float)25000);
    // Customer customer(1,new string("Rajdeep"),new string("Kolkata"),(long int)9674810029,new TimeStamp(21,7,98),(float)25000.0);
    Customer customer;
    fin.read((char*)&customer,sizeof(customer));
    
    customer.showDetails();
    fin.close();
    return 0;
}