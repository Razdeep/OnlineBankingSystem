// This is a debug class for creation of database file
// This code is just to read data from the binary file
#include<iostream>
#include<fstream>
#include"customer.h"
using namespace std;
int main()
{
    fstream fin("customer.txt",ios::binary|ios::in);
    Customer customer;
    if(!fin.is_open())
    {
        cout<<"Error: Cannot open file!!"<<endl;
    }
    else{
        // WHY ISN'T THIS WORKING?
        // WHY IS THE LAST RECORD BEING PRINTED TWICE?
        // while(!fin.eof())
        // {
        //     fin.read((char*)&customer,sizeof(customer));
        //     customer.showDetails();
        // }
        while(fin.read((char*)&customer,sizeof(customer)))
        {
            customer.showDetails();
            cout<<customer.getPass()<<endl<<endl;
        }
    }
    
    fin.close();
    return 0;
}