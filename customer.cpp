#include"customer.h"
void Customer::showDetails() const{
    using namespace std;
    cout<<ID<<endl<<name<<endl<<address<<endl<<phone<<endl<<dob.toString()<<endl<<balance<<endl;
}