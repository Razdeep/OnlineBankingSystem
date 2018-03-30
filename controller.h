#ifndef __CONTROLLER_H
#define __CONTROLLER_H
class Controller{
    public:
    void showBanner() const;
    void showMenu() const;
    void showCustomerLogin() const;
    void showCustomerPortal() const;
    bool validateCustomer() const;
    void showEmployeePortal() const;
    void showCredits() const;
};

#endif