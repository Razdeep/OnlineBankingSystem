#include<iostream>
#include"timestamp.h"
TimeStamp::TimeStamp(TimeStamp &other){
    date=other.date;
    month=other.month;
    year=other.year;
}