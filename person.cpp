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

#include"person.h"

Person::Person(const Person& other){
    this->ID=other.ID;
    strcpy(this->name,other.name);
    strcpy(this->address,other.address);
    this->phone=other.phone;
    this->dob=other.dob;
    strcpy(this->pass,other.pass);
}
int Person::getID() const{
    return this->ID;
}
const char* Person::getName() const{
    return this->name;
}
const char* Person::getAddress() const{
    return this->address;
}
long int Person::getPhone() const{
    return this->phone;
}
 TimeStamp Person::getDob() const{
    return this->dob;
}
const char* Person::getPass() const{
    return this->pass;
}
void Person::setPass(const char* newpass)
{
    std::strcpy(this->pass,newpass);
}