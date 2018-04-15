// This file is also for testing purposes only
// TESTER FOR EMPLOYEE PORTAL
#include<iostream>
#include"utility.h"
using namespace std;
int main()
{
    cout<<"1. add\n2.modify\n3. display\n4. delete\n";
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
        Controller::addCustomer();
        break;
        case 2:
        Controller::modifyCustomer();
        break;
        case 3:
        Controller::displayCustomers();
        break;
        case 4:
        Controller::deleteCustomer();
        break;
        default:
        cout<<"INVALID OPTION"<<endl;
    }
    return 0;
}