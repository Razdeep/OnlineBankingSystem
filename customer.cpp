#include"customer.h"
using namespace std;
void Customer::showDetails() const{
    
    cout<<ID<<endl<<name<<endl<<address<<endl<<phone<<endl<<dob.toString()<<endl<<balance<<endl;
}