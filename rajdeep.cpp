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