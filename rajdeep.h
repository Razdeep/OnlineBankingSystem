#include<iostream>
#ifndef __RAJDEEP_H
#define __RAJDEEP_H
class Rajdeep{
    public:
    void delay(); //@TODO
    void delay(const long int); //@TODO
    void drawLine(int); //@TODO
    void drawLine(const char,int); //@TODO with default arg
    void drawLineTrans(int,int); //@TODO
    void drawLineTrans(const char,int,int); //@TODO with default arg
    void transText(const std::string,int); //@TODO
};
#endif