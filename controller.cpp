/*  Copyright (c) Rajdeep Roy Chowdhury 2018 <rrajdeeproychowdhury@gmail.com>
*   This file is part of CSE202 Online Banking Management System Project
*
*   Permission is hereby granted, free of charge, to any person obtaining a copy of 
*   this software and associated documentation files (the "Software"), to deal in the Software 
*   without restriction, including without limitation the rights to use, copy, modify, merge, 
*   publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons 
*   to whom the Software is furnished to do so, subject to the following conditions:
*   The above copyright notice and this permission notice shall be included in all copies or 
*   substantial portions of the Software.
*
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
*   BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
*   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
*   DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
*   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/


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