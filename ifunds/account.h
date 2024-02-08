#pragma once
#include "User.h"
class account :
    public User
{
    
    string currencyname1;
    string currencyname2;
    double amount;
public:
    void get_currency_name();
    void convert_currency();
    int confirmcurrency();
    void deposit();
    int confirmdeposit();
    void withdraw();
    int confirm_withdraw();
   


};

