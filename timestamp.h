#include<iostream>
#ifndef __TIMESTAMP_H
#define __TIMESTAMP_H
class TimeStamp{
    unsigned int date;
    unsigned int month;
    unsigned int year;
    public:
    TimeStamp():date(0),month(0),year(0){};
    TimeStamp(unsigned int date, unsigned int month,unsigned int year):date(date),month(month),year(year){};

    //Copy Contructor
    TimeStamp(TimeStamp &other);
    std::string toString() const; //@TODO
};
#endif