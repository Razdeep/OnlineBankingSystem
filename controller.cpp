#include"controller.h"
#include"credential.h"
#include<iostream>

void Controller:: showBanner(){
    //@TODO
}
void Controller::showMenu()
{
    int ch;
    std::cout<<"1. Customer Login"<<std::endl;
    std::cout<<"2. Employee Login"<<std::endl;
    std::cout<<"3. Credits"<<std::endl;
    std::cout<<"4. Exit"<<std::endl;

    std::cout<<std::endl<<std::endl;
    std::cout<<"\tEnter choice (1-4) ";
    std::cin>>ch;
    switch(ch)
    {
        case 1:
        showCustomerLogin();
        break;
    }
}
void Controller::showCustomerLogin(){
    using namespace std;
    int id;
    // string pass;
    char pass[30];
    cout<<"Login ID: ";
    cin>>id;
    cout<<"Password: ";
    cin>>pass;
    Credential userCredential(id,pass);
    Credential originalCredential(123,"raj");
    //A VECTOR TO BE LOADED FROM FILE AND TO BE MATCHED WITH THE CREDENTIAL
    if(userCredential==originalCredential)
    {
        cout<<"Authentication successful"<<endl;
        // @TODO LINK TO showCustomerPortal()
    }
    else{
        cout<<"Authentication Unsuccessful"<<endl;
    }
}
void Controller::showCustomerPortal() {
    using namespace std;
    cout<<"1. View Balance"<<endl;
    cout<<"2. View Transactions"<<endl;
    cout<<"3. Change Password"<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:

        break;
        case 2:

        break;
        case 3:

        break;

        default:
        cout<<"Invalid Option"<<endl;
    }
}