#pragma once
#include "user.h"
 class Transaction :
    public User
{
    protected:
        string recieverUsername;
        int recieverWallet_id;
        double transactionAmount;
    public:
        Transaction();

        void setRecieverUsername();
        void setRecieverWallet_id();
        void setTransactionAmount();
        string getRecieverUsername();
        int getRecieverWallet_id();
        //double getTransactionAmount();

        void initiateTransaction();
        

};

