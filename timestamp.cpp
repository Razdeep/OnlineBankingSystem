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
#include<sstream>
#include<cstring>
#include"timestamp.h"
TimeStamp::TimeStamp(const TimeStamp &other){
    date=other.date;
    month=other.month;
    year=other.year;
}
std::string TimeStamp::toString() const{
    std::stringstream ss;
    ss<<date<<"/"<<month<<"/"<<year;
    return ss.str();
}
int TimeStamp::timeWeight() const{
    return ((year*10000)+(month*100)+date);
}
bool TimeStamp::operator>(const TimeStamp& other) const{
    if((timeWeight())>(other.timeWeight()))
    return true;
    else return false;
}
bool TimeStamp::operator<(const TimeStamp& other) const{
    if((timeWeight())<(other.timeWeight()))
    return true;
    else return false;
}
bool TimeStamp::operator==(const TimeStamp& other) const{
    if((timeWeight())==(other.timeWeight()))
    return true;
    else return false;
}

void TimeStamp::set(unsigned int date,unsigned int month,unsigned int year)
{
    this->date=date;
    this->month=month;
    this->year=year;
}