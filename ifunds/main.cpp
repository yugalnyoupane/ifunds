#include<iostream>
#include"user.h"
#include"DeleteAccount.h"
#include "account.h"
#include "Registration.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
int main() {
    //dashboard
    int a; //for choice FOR DASHBOARD
    int b; // for choice for main menu
    int c = 0; // for choice of account management
    Registration registers;        // registration class object
dash:
    system("cls");
    cout << "------------------------------------------------------------------------------------------------\n\n";
    cout << "                                      WELCOME TO IFUNDS!!!\n\n";
    cout << "------------------------------------------------------------------------------------------------\n\n";
    cout << "-------------------------------------------*DASHBOARD*------------------------------------------\n\n\n";
    cout << " enter 1 for registration\n";
    cout << " enter 2 for login\n";
    cout << " enter 3 for forgot password\n";
    cout << " enter 4 to exit\n";
    cout << "------------------------------------------------------------------------------------------------\n\n\n";

    cout << "enter your choice:\t";
    cin >> a;
    cout << "*********************************************************************************************************************\n\n";
    sleep_for(seconds(1));
    system("cls");
    switch (a)
    {
    case 1:


        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                  WELCOME TO REGISTRATION\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        goto regis;
    case 2:
        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                  WELCOME TO LOGIN\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        goto LOGIN;
    case 3:
        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                 WELCOME TO FORGOT PASSWORD\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        goto forgot;
    case 4:
        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                            EXIT\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        char ch;
        cout << "sure to exit:\t press 'y' for yes \n";
        cin >> ch;
        if (ch == 'y' && 'y')
        {
            system("cls");
            exit(0);
        }
        else
        {
            goto dash;
        }
    default:

        cout << "choose from the above options\n";
        sleep_for(seconds(1));
        goto dash;

    }


    //registration platform
regis:

    registers.confirm_registration();

    cout << "\n returning to dashboard.........";

    sleep_for(seconds(3));//  add delay for nanoseconds, system_clock, seconds

    goto dash;
    system("cls");
LOGIN:


    cout << "entering your account................";
    sleep_for(seconds(1));
    system("cls");

forgot:
    // for forgot password


    // after dashboard
//faceauthentication:
    // after face authentication: 

     //MAIN MENU AFTER LOGIN and face authentication ( ACCOUNT)
    account acc;        // account class object
    DeleteAccount delete_account;    // object of deleteaccount class
mainmenu:
    cout << "------------------------------------------------------------------------------------------------\n\n";
    cout << "                                      WELCOME TO MAIN MENU!!!\n\n";
    cout << "------------------------------------------------------------------------------------------------\n\n\n";
    cout << " enter 1 to deposit money\n";
    cout << " enter 2 for transaction history\n";
    cout << " enter 3 to initiate transaction\n";
    cout << " enter 4 for account management\n";
    cout << " enter 5 for currency converter\n";
    cout << " enter 6 to withdraw money \n";
    cout << " enter 7 to log out\n";
    cout << " enter 8 to exit \n";
    cout << "------------------------------------------------------------------------------------------------\n\n\n";

    cout << "enter your choice:\t";
    cin >> b;
    cout << "*********************************************************************************************************************\n\n";

    system("cls");
    switch (b)
    {
    case 1: goto ADD; //goes to deposit part       
    case 2: goto history;   // goes to transaction statement part
    case 3: goto TRANSACTION; // goes to transaction part
    case 4: goto accmanage;     //goes to deposit part
    case 5: goto currency;       //goes to currency converter part
    case 6: goto  WITHDRAW;        //goes to withdraw part
    case 7:
        char ch;
        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                 LOGOUT\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "are you sure to logout??\t press 'y' for yes \n";
        cin >> ch;
        if (ch == 'y' && 'y')
        {
            goto dash;
        }
        else
        {
            goto mainmenu;
        }
    case 8:
        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                 EXIT\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "sure to exit:\t press 'y' for yes \n";
        cin >> ch;
        if (ch == 'y' && 'y')
        {
            system("cls");
            exit(0);
        }
        else
        {
            goto mainmenu;
        }

    default:
        cout << "choose from the above options:\n";
        sleep_for(seconds(1));
        goto dash;
    }




    //labels of switch cases

ADD:       // deposit
    acc.confirmdeposit();
    cout << "\nreturning to mainmenu................";
    sleep_for(seconds(1));
    system("cls");
    goto mainmenu;

history:      // transaction history
    cout << "\nreturning to mainmenu................";
    sleep_for(seconds(1));
    system("cls");
    goto mainmenu;

TRANSACTION:      // for transaction of money
    cout << "\nreturning to mainmenu................";
    sleep_for(seconds(1));
    system("cls");
    goto mainmenu;

accmanage:

    cout << "------------------------------------------------------------------------------------------------\n\n";
    cout << "                                      WELCOME TO ACCOUNT MANAGEMENT!!!\n\n";
    cout << "------------------------------------------------------------------------------------------------\n\n";
    cout << "-------------------------------------------*OPTIONS*------------------------------------------\n\n\n";
    cout << " enter 1 for changing email\n";
    cout << " enter 2 for changing password\n";
    cout << " enter 3 for changing mpin\n";
    cout << " enter 4 for deleting account\n";
    cout << " enter 5 to return to mainmenu\n";
    cout << "------------------------------------------------------------------------------------------------\n\n\n";

    cout << "enter your choice:\t";
    cin >> c;
    switch (c)
    {
    case 1:
    case 2:
    case 3:
    case 4:

        delete_account.confirmDeletion();
        cout << "\nreturning to mainmenu................";
        sleep_for(seconds(1));
        system("cls");
        goto mainmenu;
    case 5:
        cout << "\nreturning to mainmenu................";
        sleep_for(seconds(1));
        system("cls");
        goto mainmenu;
    default:
        cout << "choose from the above options:\n";
        cout << "\nreturning to mainmenu................";
        sleep_for(seconds(1));
        system("cls");
        goto mainmenu;
    }




currency:     //currency converter
    acc.confirmcurrency();
    cout << "\nreturning to mainmenu................";
    sleep_for(seconds(1));
    system("cls");
    goto mainmenu;


WITHDRAW:      //witthdraw
    acc.confirm_withdraw();
    cout << "\nreturning to mainmenu................";
    sleep_for(seconds(1));
    system("cls");
    goto mainmenu;









    return 0;
}