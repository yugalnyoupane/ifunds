#pragma once
#include "user.h"

using namespace std;
class DeleteAccount :
    public User
{
    protected:
        string tempUsername, tempPassword;

    public:
        DeleteAccount();
        void setTempUsername();
        void setTempPassword();
        int confirmDeletion();
        //void deleteAccount(string username, string password);
    };

