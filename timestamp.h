#ifndef __TIMESTAMP_H
#define __TIMESTAMP_H
class TimeStamp{
    unsigned int date;
    unsigned int month;
    unsigned int year;
    public:
    TimeStamp();
    void getTime() const; //@TODO
};
#endif