// This file is for individual tetsting of files

#include<iostream>
#include"timestamp.h"
#include"timestamp.cpp"
using namespace std;
int main()
{
    TimeStamp t1(31,8,1998),t2(21,07,1998);
    if(t1>t2)
    cout<<"I'm older"<<endl;
    if(t2<t1)
    cout<<"She's younger"<<endl;
    if(t1==t2);else
    cout<<"Different ages"<<endl;

    return 0;
}