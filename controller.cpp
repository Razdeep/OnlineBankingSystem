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
#include"employee.h"
#include"rajdeep.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<algorithm>
void Controller::showBanner(){
    system("clear");
    Rajdeep rajdeep;
    rajdeep.drawLine(100);
    std::cout<<"\t\tBMS - Banking Management System"<<std::endl;
    rajdeep.drawLine(100);
}
void Controller::showMenu()
{
    int ch;
    std::cout<<"1. Customer Login"<<std::endl;
    std::cout<<"2. Employee Login"<<std::endl;
    std::cout<<"3. Admin (id: raj, pass: raj)"<<std::endl;
    std::cout<<"4. Credits"<<std::endl;
    std::cout<<"5. License"<<std::endl;
    std::cout<<"6. Exit"<<std::endl;

    std::cout<<std::endl<<std::endl;
    std::cout<<"\tEnter choice (1-6) ";
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
        showLicense();
        break;
        case 6:
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
    bool running=true;
    while(running)
    {
        std::vector<Customer> custVector;
        std::fstream fin("customer.txt",std::ios::binary|std::ios::in);
        Customer customer;
        while(fin.read((char*)&customer,sizeof(Customer))){
            custVector.push_back(customer);
        }

        std::cout<<"1. View Balance"<<std::endl;
        std::cout<<"2. View Transactions"<<std::endl;
        std::cout<<"3. Change Password"<<std::endl;
        std::cout<<"4. Logout to Mainmenu"<<std::endl;
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
            {
                std::cout<<"THIS PART IS NOT IMPLEMENTED YET. @TODO"<<std::endl;
            }
            break;
            case 3:
            Controller::changeCustomerPassword(SESSION);
            break;
            case 4:
            running=false;
            break;
            default:
            std::cout<<"Invalid Option"<<std::endl;
        }
    }
}
void Controller::showEmployeeLogin()
{
    Credential credTemp;
    Employee emp;
    std::vector<Credential> credVector;
    std::fstream fin("employee.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&emp,sizeof(Employee))){
        credTemp.setID(emp.getID());
        credTemp.setPass(emp.getPass());
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
            std::cout<<"Authentication successful"<<std::endl<<std::endl;
            SUCCESS=true;
            SESSION=userCredential.ID;
            showEmployeePortal(SESSION);
        }
    }
    if(!SUCCESS)
    {
        std::cout<<"Authentication unsuccessful"<<std::endl;
    }
}
void Controller::showEmployeePortal(const int SESSION)
{
    // ---------------------------
    // DOING
    // ------------------------
    while(1)
    {
        std::cout<<"1. Add Customer"<<std::endl;
        std::cout<<"2. Modify Customer"<<std::endl;
        std::cout<<"3. View Customers(DEFAULT CHRONOLOGICAL)"<<std::endl;
        std::cout<<"4. View Customers by"<<std::endl;
        std::cout<<"5. Search Customer"<<std::endl;
        std::cout<<"6. Deposit Money to Customer account"<<std::endl;
        std::cout<<"7. Withdraw Money from Customer account"<<std::endl;
        std::cout<<"8. Logout and return to mainmenu"<<std::endl;
        int ch;
        std::cin>>ch;
        bool running=true;
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
            Controller::displayCustomersBy();
            break;
            case 5:
            std::cout<<"@TODO call Rajdeep to implement this"<<std::endl;
            break;
            case 6:
            Controller::deposit();
            break;
            case 7:
            Controller::withdraw();
            break;
            case 8:
            running=false;
            break;
            default:
            std::cout<<"Invalid Option"<<std::endl;
        }
        if(!running)
        break;
    }
}
void Controller::showAdmin()
{
    bool running=true;
    while(1)
    {
    Rajdeep rajdeep;
    rajdeep.drawLine(50);
    std::cout<<"\tADMIN PORTAL"<<std::endl;
    rajdeep.drawLine(50);
    std::cout<<"1. Add Employee\n2. Modify Employee\n3. Display Employees\n4. Delete Employees\n5. Add customer\n6. Modify Customer\n7. Display Customers\n8. Delete Customer\n9. Deposit to Customer A/C\n10. Withdraw from Customer A/C\n11. Logout to mainmenu\n";
    int ch;
    std::cout<<"Choose any option: ";
    std::cin>>ch;
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
        case 5:
        Controller::addCustomer();
        break;
        case 6:
        Controller::modifyCustomer();
        break;
        case 7:
        Controller::displayCustomers();
        break;
        case 8:
        Controller::deleteCustomer();
        break;
        case 9:
        Controller::deposit();
        break;
        case 10:
        Controller::withdraw();
        break;
        case 11:
        running=false;
        break;
        default:
        std::cout<<"Invalid Choice"<<std::endl;
        }
        if(!running)
        break;
    }
    
}
void Controller::showCredits()
{
    Rajdeep rajdeep;
    system("clear");
    rajdeep.drawLine(100);
    std::cout<<"\t\tBMS - Banking Management System"<<std::endl;
    rajdeep.drawLine(100);
    std::cout<<std::endl<<"\tCreated by Rajdeep Roy Chowdhury<rrajdeeproychowdhury@gmail.com>"<<std::endl;
    std::cout<<"Btech CSE (2nd Sem), Lovely Professional University, Punjab, India"<<std::endl;
    std::cout<<"Reg: 11712546"<<std::endl<<"Roll: RK17WXB55"<<std::endl;
    std::cout<<std::endl<<"This Banking Management System serves as project of CSE202(Object Oriented Programming)"<<std::endl;
    rajdeep.drawLine(100);
    char buff[10];
    std::cout<<"Y to Continue"<<std::endl;
    std::cin>>buff;
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
        std::cin.ignore();
        std::cout<<"Enter Customer Name; "<<std::endl;
        std::cin.getline(name,30);
        std::cout<<"Enter address "<<std::endl;
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
void Controller::modifyCustomer()
{
    Rajdeep rajdeep;
    std::vector<Customer> custVector;
    Customer cust;
    std::fstream fin("customer.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&cust,sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();

    displayCustomers();

    int id;
    std::cout<<"Enter the ID of the customer to be modified ";
    std::cin>>id;
    // CHECKING WHETHER ENTERED VALUE EXIST
    bool flag=false;
    int count=0;
    for(std::vector<Customer>::iterator itr=custVector.begin();
    itr!=custVector.end();++itr,++count)
    {
        if(itr->getID()==id)
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
        char name[30],address[30],pass[30];
        long int phone;
        TimeStamp dob;
        float bal;
        std::cout<<"Enter Customer Name; "<<std::endl;
        std::cin.ignore();
        std::cin.getline(name,30);
        std::cout<<"Enter address "<<std::endl;
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
        custVector.at(count)=cust;

        //WRITING CUSTVECTOR TO THE CUSTOMER.TXT
        std::fstream fout("customer.txt",std::ios::binary|std::ios::out|std::ios::trunc);
        for(int i=0;i<custVector.size();i++)
        {
            fout.write((char*)&custVector.at(i),sizeof(Customer));
        }
        fout.close();
    }
    else{
        std::cout<<"Customer account that is to be modified doesnot exist"<<std::endl;
    }
}
void Controller::displayCustomers()
{
    Rajdeep rajdeep;
    std::vector<Customer> custVector;
    Customer cust;
    std::fstream fin("customer.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&cust,sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();
    rajdeep.drawLine(100);
    std::cout<<"ID\tNAME\tADDRESS\tPHONE\t\tDOB\tPASSWORD\tBALANCE"<<std::endl;
    rajdeep.drawLine(100);
    for(std::vector<Customer>::iterator itr=custVector.begin();
    itr!=custVector.end();++itr)
    {
        std::cout<<itr->getID()<<"\t"<<itr->getName()<<"\t"<<itr->getAddress()<<"\t"
        <<itr->getPhone()<<"\t"<<(itr->getDob()).toString()<<"\t"<<itr->getPass()<<
        "\t"<<itr->getBalance()<<std::endl;
    }
    rajdeep.drawLine(100);
    std::cout<<std::endl;
}
void Controller::deleteCustomer(){
    Rajdeep rajdeep;
    std::vector<Customer> custVector;
    Customer cust;
    std::fstream fin("customer.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&cust,sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();
    int id;
    std::cout<<"Enter the ID of the customer to be deleted ";
    std::cin>>id;
    for(int i=0;i<custVector.size();i++)
    {
        if(custVector[i].getID()==id)
        {
            custVector.erase(custVector.begin()+i);
        }
    }
    // TRUNCATING THE CUSTVECTOR TO THE CUSTOMER.TEXT
    std::fstream fout("customer.txt",std::ios::binary|std::ios::out|std::ios::trunc);
    for(int i=0;i<custVector.size();++i)
    {
        fout.write((char*)&custVector[i],sizeof(Customer));
    }
    fout.close();
}
void Controller::displayCustomersBy(){
    Rajdeep rajdeep;
    std::vector<Customer> custVector;
    Customer cust;
    std::fstream fin("customer.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&cust,sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();
    rajdeep.drawLine(100);
    // std::cout<<"Sorted to names..."<<std::endl;
    // std::sort(custVector.begin(),custVector.end(),sortCustomerByName);
    int ch;
    std::cout<<"1. Sort by ID "<<std::endl;
    std::cout<<"2. Sort by Name "<<std::endl;
    std::cout<<"3. Sort by Date of Birth "<<std::endl;
    std::cout<<"4. Sort by Balance "<<std::endl;
    std::cin>>ch;
    switch(ch)
    {
        case 1:
        std::sort(custVector.begin(),custVector.end(),sortCustomerById);
        break;
        case 2:
        std::sort(custVector.begin(),custVector.end(),sortCustomerByName);
        break;
        case 3:
        std::sort(custVector.begin(),custVector.end(),sortCustomerByDob);
        break;
        case 4:
        std::sort(custVector.begin(),custVector.end(),sortCustomerByBalance);
        break;
    }
    std::cout<<"ID\tNAME\tADDRESS\tPHONE\t\tDOB\tPASSWORD\tBALANCE"<<std::endl;
    rajdeep.drawLine(100);
    for(std::vector<Customer>::iterator itr=custVector.begin();
    itr!=custVector.end();++itr)
    {
        std::cout<<itr->getID()<<"\t"<<itr->getName()<<"\t"<<itr->getAddress()<<"\t"
        <<itr->getPhone()<<"\t"<<(itr->getDob()).toString()<<"\t"<<itr->getPass()<<
        "\t"<<itr->getBalance()<<std::endl;
    }
    rajdeep.drawLine(100);
    std::cout<<std::endl;
}
void Controller::addEmployee()
{
    std::vector<Employee> empVector;
    std::fstream fin("employee.txt",std::ios::binary|std::ios::in);
    Employee employee;
    while(fin.read((char*)&employee,sizeof(Employee))){
         empVector.push_back(employee);
    }
    fin.close();
    int id;
    std::cout<<"Enter Employee ID ";
    std::cin>>id;
    bool flag=true;
    // // CHECKING WHETHER ID IS ALREADY EXISTING IN OUR DATABASE
    for(std::vector<Employee>::iterator itr=empVector.begin(); itr!=empVector.end();++itr)
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
        float salary;
        std::cout<<"Enter Employee Name: "<<std::endl;
        std::cin.ignore();
        std::cin.getline(name,30);
        std::cout<<"Enter address "<<std::endl;
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
        std::cout<<"Enter Salary ";
        std::cin>>salary;
        Employee emp(id,name,address,phone,dob,pass,salary);
        std::fstream fout("employee.txt",std::ios::binary|std::ios::out|std::ios::app);
        fout.write((char*)&emp,sizeof(Employee));
        fout.close();
    }
    else{
        std::cout<<"Operation unsuccessful. Record with similar ID already exists."<<std::endl;
    }
}
void Controller::modifyEmployee()
{
    Rajdeep rajdeep;
    std::vector<Employee> empVector;
    Employee emp;
    std::fstream fin("employee.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&emp,sizeof(Employee)))
    {
        empVector.push_back(emp);
    }
    fin.close();

    displayEmployees();

    int id;
    std::cout<<"Enter the ID of the employee to be modified ";
    std::cin>>id;
    // // CHECKING WHETHER ENTERED VALUE EXIST
    bool flag=false;
    int count=0;
    for(std::vector<Employee>::iterator itr=empVector.begin();
    itr!=empVector.end();++itr,++count)
    {
        if(itr->getID()==id)
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
        char name[30],address[30],pass[30];
        long int phone;
        TimeStamp dob;
        float salary;
        std::cout<<"Enter Employee Name; "<<std::endl;
        std::cin.ignore();
        std::cin.getline(name,30);
        std::cout<<"Enter address "<<std::endl;
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
        std::cout<<"Enter Salary ";
        std::cin>>salary;
        Employee emp(id,name,address,phone,dob,pass,salary);
        empVector.at(count)=emp;

        //WRITING CUSTVECTOR TO THE EMPLOYEE.TXT
        std::fstream fout("employee.txt",std::ios::binary|std::ios::out|std::ios::trunc);
        for(int i=0;i<empVector.size();i++)
        {
            fout.write((char*)&empVector.at(i),sizeof(Employee));
        }
        fout.close();
    }
    else{
        std::cout<<"Customer account that is to be modified doesnot exist"<<std::endl;
    }
}
void Controller::displayEmployees()
{
    Rajdeep rajdeep;
    std::vector<Employee> empVector;
    Employee emp;
    std::fstream fin("employee.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&emp,sizeof(Employee)))
    {
        empVector.push_back(emp);
    }
    fin.close();
    rajdeep.drawLine(100);
    std::cout<<"ID\tNAME\tADDRESS\tPHONE\t\tDOB\tPASSWORD\tSALARY"<<std::endl;
    rajdeep.drawLine(100);
    for(std::vector<Employee>::iterator itr=empVector.begin();
    itr!=empVector.end();++itr)
    {
        std::cout<<itr->getID()<<"\t"<<itr->getName()<<"\t"<<itr->getAddress()<<"\t"
        <<itr->getPhone()<<"\t"<<(itr->getDob()).toString()<<"\t"<<itr->getPass()<<
        "\t"<<itr->getSalary()<<std::endl;
    }
    rajdeep.drawLine(100);
    std::cout<<std::endl;
}
void Controller::deleteEmployee()
{
    Rajdeep rajdeep;
    std::vector<Employee> empVector;
    Employee emp;
    std::fstream fin("employee.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&emp,sizeof(Employee)))
    {
        empVector.push_back(emp);
    }
    fin.close();
    int id;
    std::cout<<"Enter the ID of the employee to be deleted ";
    std::cin>>id;
    for(int i=0;i<empVector.size();i++)
    {
        if(empVector[i].getID()==id)
        {
            empVector.erase(empVector.begin()+i);
        }
    }
    // TRUNCATING THE CUSTVECTOR TO THE EMPLOYEE.TEXT
    std::fstream fout("employee.txt",std::ios::binary|std::ios::out|std::ios::trunc);
    for(int i=0;i<empVector.size();++i)
    {
        fout.write((char*)&empVector[i],sizeof(Employee));
    }
    fout.close();
}
void Controller::deposit(){
    Rajdeep rajdeep;
    //LOADING DATA
    std::vector<Customer> custVector;
    Customer cust;
    std::fstream fin("customer.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&cust,sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();
    rajdeep.drawLine(100);
    std::cout<<"Deposit Window"<<std::endl;
    rajdeep.drawLine(100);
    int id;
    float money;
    std::cout<<"Enter the ID that you want the money to be deposited ";
    std::cin>>id;
    std::cout<<"Enter the amount to deposited ";
    std::cin>>money;
    bool SUCCESS=false;
    for(std::vector<Customer>::iterator itr=custVector.begin();itr!=custVector.end();++itr)
    {
        if(itr->getID()==id)
        {
            itr->deposit(money);
            SUCCESS=true;
            break;
        }
    }
    //WRITING CUSTVECTOR TO THE CUSTOMER.TXT
    std::fstream fout("customer.txt",std::ios::binary|std::ios::out|std::ios::trunc);
    for(int i=0;i<custVector.size();i++)
    {
        fout.write((char*)&custVector.at(i),sizeof(Customer));
    }
    fout.close();
    if(SUCCESS)
    std::cout<<"Successfully deposited Rs. "<<money<<std::endl;
    else
    std::cout<<"Transaction could not be completed. Please contact the nearest Branch."<<std::endl;
}
void Controller::withdraw()
{
    Rajdeep rajdeep;
    //LOADING DATA
    std::vector<Customer> custVector;
    Customer cust;
    std::fstream fin("customer.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&cust,sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();
    rajdeep.drawLine(100);
    std::cout<<"Withdraw Window"<<std::endl;
    rajdeep.drawLine(100);
    int id;
    float money;
    std::cout<<"Enter the ID that you want the money to be withdrawn from ";
    std::cin>>id;
    std::cout<<"Enter the amount to withdraw ";
    std::cin>>money;
    bool SUCCESS=false;
    for(std::vector<Customer>::iterator itr=custVector.begin();itr!=custVector.end();++itr)
    {
        if(itr->getID()==id)
        {
            itr->withdraw(money);
            SUCCESS=true;
            break;
        }
    }
    // //WRITING CUSTVECTOR TO THE CUSTOMER.TXT
    std::fstream fout("customer.txt",std::ios::binary|std::ios::out|std::ios::trunc);
    for(int i=0;i<custVector.size();i++)
    {
        fout.write((char*)&custVector.at(i),sizeof(Customer));
    }
    fout.close();
    if(SUCCESS)
    std::cout<<"Successfully withdrawn Rs. "<<money<<std::endl;
    else
    std::cout<<"Transaction could not be completed. Please contact the nearest Branch."<<std::endl;
}
void Controller::changeCustomerPassword(const int SESSION)
{
    Rajdeep rajdeep;
    //LOADING DATA
    std::vector<Customer> custVector;
    Customer cust;
    std::fstream fin("customer.txt",std::ios::binary|std::ios::in);
    while(fin.read((char*)&cust,sizeof(Customer)))
    {
        custVector.push_back(cust);
    }
    fin.close();

    char prevpass[30],newpass[30];
    rajdeep.drawLine(100);
    std::cout<<"CHANGE PASSWORD"<<std::endl;
    rajdeep.drawLine(100);
    std::cout<<"Enter the previous password ";
    std::cin.ignore();
    std::cin.getline(prevpass,30);
    std::cout<<"Enter new password ";
    std::cin.getline(newpass,30);
    bool SUCCESS=false;
    for(std::vector<Customer>::iterator itr=custVector.begin();
    itr!=custVector.end();++itr)
    {
        if((itr->getID()==SESSION) && !strcmp(itr->getPass(),prevpass))
        {
            itr->setPass(newpass);
            SUCCESS=true;
            break;
        }
    }
    if(SUCCESS)
    std::cout<<"Successfully changed your password. Kindly dont share your password with anyone else."<<std::endl;
    else{ std::cout<<"Could not process your request. Please visit the nearest branch."<<std::endl;
    std::cout<<"Possibly, you have entered wrong previous password."<<std::endl;
    }
    // //WRITING CUSTVECTOR TO THE CUSTOMER.TXT
    std::fstream fout("customer.txt",std::ios::binary|std::ios::out|std::ios::trunc);
    for(int i=0;i<custVector.size();i++)
    {
        fout.write((char*)&custVector.at(i),sizeof(Customer));
    }
    fout.close();
}
void Controller::showLicense()
{
    Rajdeep rajdeep;
    system("clear");
    std::fstream fin("LICENSE",std::ios::in);
    std::string line;
    while(!fin.eof())
    {
        std::getline(fin,line);
        std::cout<<line;
    }
    std::cout<<std::endl;
    rajdeep.drawLine(100);
    fin.close();
    char buff[10];
    std::cout<<"Y to Continue"<<std::endl;
    std::cin>>buff;
}

//***********SORTING ALGORITHMS*************
bool Controller::sortCustomerByName(const Customer& c1,const Customer& c2)
{
    if(strcmp(c1.getName(),c2.getName())<0)
    return true;
    else return false;
}
bool Controller::sortCustomerByDob(const Customer& c1,const Customer& c2)
{
    if(c1.getDob()<c2.getDob())
    return true;
    else return false;
}
bool Controller::sortCustomerById(const Customer& c1,const Customer& c2)
{
    if(c1.getID()<c2.getID())
    return true;
    else return false;
}
bool Controller::sortCustomerByBalance(const Customer& c1,const Customer& c2)
{
    if(c1.getBalance()<c2.getBalance())
    return true;
    else return false;
}
//********SORTING ALGO ENDS****************