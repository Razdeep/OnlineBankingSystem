// TESTER FOR ADMIN PORTAL
// THIS IS NOT CONTRIBUTING TO THE EXECUTABLE FILE
// THIS IS JUST TO TEST THE addEmployee(),modifyEmployee(),
// displayEmployees(),deleteEmployees()
#include<iostream>
#include"utility.h"

int main()
{
    using namespace std;
    Rajdeep rajdeep;
    rajdeep.drawLine(50);
    cout<<"\tADMIN PORTAL TESTER"<<endl;
    rajdeep.drawLine(50);
    cout<<"1. Add Employee\n2. Modify Employee\n3. Display Employees\n4. Delete Employees\n";
    int ch;
    cin>>ch;
    switch(ch){
        case 1:
        Controller::addEmployee();
        break;
        case 2:
        Controller::modifyEmployee();
        break;
        case 3:
        Controller::displayEmployees();
        break;
        case 4:
        Controller::deleteEmployee();
        break;
        default:
        cout<<"Invalid Choice"<<endl;
    }
    return 0;
}