// This is a debug class for creation of database file
// This code is just to add data to the binary file
#include<iostream>
#include<fstream>
#include"customer.h"
using namespace std;
int main()
{
    fstream fout("customer.txt",ios::binary);
    // |ios::ate);
    Customer customer();
    return 0;
}