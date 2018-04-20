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


#include<iostream>
#include"customer.h"
#ifndef __CONTROLLER_H
#define __CONTROLLER_H
class Controller{
    static bool sortCustomerByName(const Customer&,const Customer&);
    static bool sortCustomerByDob(const Customer&,const Customer&);
    static bool sortCustomerById(const Customer&,const Customer&);
    static bool sortCustomerByBalance(const Customer&,const Customer&);
    public:
    static void showBanner();
    static void showMenu();
    static void showCustomerLogin();
    static void showCustomerPortal(const int SESSION);
    static void showEmployeeLogin();
    static void showEmployeePortal(const int SESSION);
    static void showAdmin();
    static void showCredits();
    static void addCustomer();
    static void modifyCustomer();
    static void displayCustomers();
    static void deleteCustomer();
    static void displayCustomersBy();
    static void addEmployee();
    static void modifyEmployee();
    static void displayEmployees();
    static void deleteEmployee();
    static void deposit();// Acts as withdraw when passed negative value
    static void withdraw();
    static void changeCustomerPassword(const int SESSION);
    static void showLicense();
    
};

#endif