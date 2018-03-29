#include<iostream>
#ifndef __RAJDEEP_H
#define __RAJDEEP_H
class Rajdeep{
    public:
    void delay() const; //@TODO
    void delay(const long int) const; //@TODO
    void drawLine(int) const; //@TODO
    void drawLine(const char,int) const; //@TODO with default arg
    void drawLineTrans(int,int) const; //@TODO
    void drawLineTrans(const char,int,int) const; //@TODO with default arg
    void transText(const std::string,int) const; //@TODO
};
#endif