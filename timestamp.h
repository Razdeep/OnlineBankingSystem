#include<iostream>
#ifndef __TIMESTAMP_H
#define __TIMESTAMP_H
class TimeStamp{
    unsigned int date;
    unsigned int month;
    unsigned int year;

    int timeWeight() const;
                        // RETURNS (year*10000)+(month*100)+(date*1)

    public:
    TimeStamp():date(0),month(0),year(0){};
    TimeStamp(unsigned int date, unsigned int month,unsigned int year):date(date),month(month),year(year){};

    //Copy Contructor
    TimeStamp(TimeStamp &other);

    std::string toString() const;   // @TODO

    bool operator>(const TimeStamp&) const; // @DONE
    bool operator<(const TimeStamp&) const; // @DONE
    bool operator==(const TimeStamp&) const; // @DONE
};
#endif