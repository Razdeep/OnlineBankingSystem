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
#include"customer.h"
#include<iostream>
#include<fstream>
#include<vector>
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
    Credential credTemp;
    Customer cust;
    std::vector<Credential> credVector;
    std::fstream fin("customer.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&cust,sizeof(Customer))){
        credTemp.setID(cust.getID());
        credTemp.setPass(cust.getPass());
        credVector.push_back(credTemp);
    }
    fin.close();
    int id;
    char pass[30];
    std::cout<<"Login ID: ";
    std::cin>>id;
    std::cout<<"Password: ";
    std::cin>>pass;
    Credential userCredential(id,pass);
    bool SUCCESS=false;
    int SESSION=-1;
    for(std::vector<Credential>::iterator itr=credVector.begin(); itr!=credVector.end(); ++itr)
    {
        if(userCredential==*itr)
        {
            std::cout<<"Authentication successful"<<std::endl;
            SUCCESS=true;
            SESSION=userCredential.ID;
            showCustomerPortal(SESSION);
        }
    }
    if(!SUCCESS)
    {
        std::cout<<"Authentication unsuccessful"<<std::endl;
    }
}



void Controller::showCustomerPortal(const int SESSION) {
    /***HAVING ISSUES IN THESE CODES***/
    
    std::vector<Customer> custVector;
    std::fstream fin("customer.txt",std::ios::binary|std::ios::in);
    Customer customer;
    while(fin.read((char*)&customer,sizeof(Customer))){
        custVector.push_back(customer);
    }

    std::cout<<"1. View Balance"<<std::endl;
    std::cout<<"2. View Transactions"<<std::endl;
    std::cout<<"3. Change Password"<<std::endl;
    int ch;
    std::cin>>ch;
    switch(ch)
    {
        case 1:
        // showBalance(custVector,SESSION);    
        break;
        case 2:

        break;
        case 3:

        break;

        default:
        std::cout<<"Invalid Option"<<std::endl;
    }
}
