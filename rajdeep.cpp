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

#include"rajdeep.h"
void Rajdeep::delay() const{
    int i,j;
    for(i=0;i<100000;i++)
    for(j=0;j<10000;j++);
    // @TODO Calibration to be done
}
void Rajdeep::delay(const long int ms) const{
    //@TODO
}
void Rajdeep::drawLine(int n=50) const{
    int i;
    for(i=0;i<n;i++)
    {
        std::cout<<"-";
    }
    std::cout<<std::endl;
}
void Rajdeep::drawLine(const char ch,int n=50) const{
    int i;
    for(i=0;i<n;i++)
    {
        std::cout<<ch;
    }
    std::cout<<std::endl;
}
void Rajdeep::drawLineTrans(int n=50,int ms=50) const{
    int i;
    for(i=0;i<n;i++)
    {
        std::cout<<"-";
        delay(100);
    }
    std::cout<<std::endl;
}
void Rajdeep::drawLineTrans(const char ch,int n=50,int ms=50) const{
     int i;
    for(i=0;i<n;i++)
    {
        std::cout<<ch;
        delay(100);
    }
    std::cout<<std::endl;
}
void Rajdeep::transText(const std::string str,int ms) const{
    //@TODO
}