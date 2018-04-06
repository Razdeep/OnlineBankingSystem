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
    return std::string("RRC: BUILT STRING TO BE RETURNED FROM HERE");
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