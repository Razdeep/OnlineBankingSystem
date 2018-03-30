#ifndef __TIMESTAMP_H
#define __TIMESTAMP_H
class TimeStamp{
    unsigned int date;
    unsigned int month;
    unsigned int year;
    public:
    TimeStamp(unsigned int date, unsigned int month,unsigned int year):date(date),month(month),year(year){};

    //Copy Contructor
    TimeStamp(TimeStamp &other);
    void getTime() const; //@TODO
};
#endif