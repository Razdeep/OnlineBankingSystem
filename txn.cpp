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
#include<iomanip>
#include"txn.h"

void Txn::printTxn() const{
    Rajdeep rajdeep;
    rajdeep.drawLine(30);
    std::cout<<"\tMINI-STATEMENT"<<std::endl;
    rajdeep.drawLine(30);
    std::cout<<std::setw(20)<<"ID : "<<this->id<<std::endl
    <<std::setw(20)<<"Name : "<<(this->cust).getName()<<std::endl
    <<std::setw(20)<<"Txn Date : "<<(this->ts).toString()<<std::endl
    <<std::setw(20)<<"Amount : "<<(this->amount)<<std::endl
    <<std::setw(20)<<"Transaction type: "<<((type=='d'||type=='D')?"Debit":"Credit")<<std::endl;
    rajdeep.drawLine(30);
    std::cout<<"Have a nice day..."<<std::endl;
    rajdeep.drawLine(30);
}
