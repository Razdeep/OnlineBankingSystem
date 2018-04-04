#include"credential.h"

bool Credential::operator==(const Credential &other)
{
    if(id==other.id && (strcmp(pass,other.pass)==0))
    {
        return true;
    }
    else{
        return false;
    }
}