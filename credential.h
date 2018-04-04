#include<iostream>
#include<cstring>
#ifndef __CREDENTIAL_H
#define __CREDENTIAL_H
class Credential{
    public:
    int id;
    // std::string pass;
    char pass[30];
    // Credential(int id,std::string pass):id(id),pass(pass){}
    Credential(int id,char* pass):id(id){
        strcpy(this->pass,pass);
    };
    bool operator==(const Credential&);
};
#endif