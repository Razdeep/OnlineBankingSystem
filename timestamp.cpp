#include<iostream>
#include"timestamp.h"
TimeStamp::TimeStamp(TimeStamp &other){
    date=other.date;
    month=other.month;
    year=other.year;
}
std::string TimeStamp::toString() const{
    // IOMANIP TO IMPLEMENTED HERE
    std::cout<<date<<"/"<<month<<"/"<<year<<std::endl;
    //STRINGBUILDER TO BE IMPLEMENTED
}