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
#include<cstdlib>
void Controller:: showBanner(){
    //@TODO
}
void Controller::showMenu()
{
    int ch;
    std::cout<<"1. Customer Login"<<std::endl;
    std::cout<<"2. Employee Login"<<std::endl;
    std::cout<<"3. Admin (id: raj, pass: raj)"<<std::endl;
    std::cout<<"4. Credits"<<std::endl;
    std::cout<<"5. Exit"<<std::endl;

    std::cout<<std::endl<<std::endl;
    std::cout<<"\tEnter choice (1-4) ";
    std::cin>>ch;
    switch(ch)
    {
        case 1:
        showCustomerLogin();
        break;
        case 2:
        showEmployeeLogin();
        break;
        case 3:
        {
            std::string id,pass;
            std::cout<<"Enter your ID:\t";
            std::cin>>id;
            std::cout<<"Enter your Password\t";
            std::cin>>pass;
            if(id=="raj" && pass=="raj")
            showAdmin();
            else std::cout<<"Invalid Password"<<std::endl;
        }
        break;
        case 4:
        showCredits();
        break;
        case 5:
        exit(0);
        default:
        std::cout<<"Invalid Input. Try again..."<<std::endl;
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
        {
            for(std::vector<Customer>::iterator itr=custVector.begin();
            itr!=custVector.end();itr++)
            {
                if(itr->getID()==SESSION)
                {
                    itr->showDetails();
                }
            }
        }
        break;
        case 2:

        break;
        case 3:

        break;

        default:
        std::cout<<"Invalid Option"<<std::endl;
    }
}

void Controller::addCustomer()
{
    std::vector<Customer> custVector;
    std::fstream fin("customer.txt",std::ios::binary|std::ios::in);
    Customer customer;
    while(fin.read((char*)&customer,sizeof(Customer))){
        custVector.push_back(customer);
    }
    fin.close();
    int id;
    std::cout<<"Enter Customer ID ";
    std::cin>>id;
    bool flag=true;
    // CHECKING WHETHER ID IS ALREADY EXISTING IN OUR DATABASE
    for(std::vector<Customer>::iterator itr=custVector.begin(); itr!=custVector.end();++itr)
    {
        if(itr->getID()==id)
        {
            flag=false;
            break;
        }
    }
    if(flag) // NO SAME EXISTING ID, SO, NO ISSUE TO SAVE
    {
    
        char name[30],address[30],pass[30];
        long int phone;
        TimeStamp dob;
        float bal;
        std::cout<<"Enter Customer Name; "<<std::endl;
        std::cin.ignore();
        std::cin.getline(name,30);
        std::cout<<"Enter address "<<std::endl;
        std::cin.ignore();
        std::cin.getline(address,30);
        std::cout<<"Enter phone "<<std::endl;
        std::cin>>phone;
        std::cout<<"Enter Date of Birth (DD MM YYYY) [SEPARATED BY SPACES] ";
        int dd,mm,yy;
        std::cin>>dd>>mm>>yy;
        dob.set(dd,mm,yy);
        std::cout<<"Enter Password ";
        std::cin.ignore();
        std::cin.getline(pass,30);
        std::cout<<"Enter Balance ";
        std::cin>>bal;
        Customer cust(id,name,address,phone,dob,pass,bal);
        std::fstream fout("customer.txt",std::ios::binary|std::ios::out|std::ios::app);
        fout.write((char*)&cust,sizeof(Customer));
        fout.close();
    }
    else{
        std::cout<<"Operation unsuccessful. Record with similar ID already exists."<<std::endl;
    }
}
void Controller::showEmployeeLogin()
{
    // @TODO
    std::cout<<"@TODO RAJDEEP"<<std::endl;
}
void Controller::showAdmin()
{
    // @TODO
    std::cout<<"@TODO RAJDEEP"<<std::endl;
}
void Controller::showCredits()
{
     // @TODO
    std::cout<<"@TODO RAJDEEP"<<std::endl;
}