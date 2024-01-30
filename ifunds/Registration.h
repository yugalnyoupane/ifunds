#pragma once
#include "User.h"
class Registration :
    public User
{
    string email;
    int age;
    int mpin;
public:
    void get_data();
    void get_user_id();
    int confirm_registration();
};

