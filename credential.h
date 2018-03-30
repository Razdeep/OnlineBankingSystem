#include<iostream>
#ifndef __CREDENTIAL_H
#define __CREDENTIAL_H
class Credential{
    public:
    int id;
    std::string pass;
    Credential(int id,std::string pass):id(id),pass(pass){}
};
#endif