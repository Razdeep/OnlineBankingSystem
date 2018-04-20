#include<iostream>
#include<cstdlib>
#include"utility.h"
using namespace std;

int main()
{
    while(1)
    {
        Controller::showBanner();
        Controller::showMenu();
    }
    return 0;
}