#include<iostream>
#include"user.h"
#include"DeleteAccount.h"
#include"Transaction.h"
#include "Registration.h"

int main() {


    //goto dash;
    // after dashboard
//faceauthentication:
    // after face authentication: 
    system("cls");


     mainmenu:
        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                      WELCOME TO MAIN MENU!!!\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n\n";
        cout << " enter 1 to add funds\n";
        cout << " enter 2 for transaction history\n";
        cout << " enter 3 to initiate transaction\n";
        cout << " enter 4 for account management\n";
        cout << " enter 5 for currency convertern\n";
        cout << " enter 6 for deleting your account\n";
        cout << " enter 7 to log out\n";
        cout << " enter 8 to exit \n";
        cout << "------------------------------------------------------------------------------------------------\n\n\n";

        int b;
        cout << "enter your choice:\t";
        cin >> b;
        cout << "*********************************************************************************************************************\n\n";

        system("cls");
        switch (b)
        {
        /*case 1:


            cout << "------------------------------------------------------------------------------------------------\n\n";
            cout << "                                 WELCOME TO ADD FUNDS\n\n";
            cout << "------------------------------------------------------------------------------------------------\n\n";
            //goto ADD;
        //case 2:
        */
        case 3: {
            Transaction make_transaction;

            make_transaction.initiateTransaction();
        }
        case 6: {
            DeleteAccount delete_account;
            delete_account.confirmDeletion();
        }
            
        /*case 7:
            char ch;
            cout << "------------------------------------------------------------------------------------------------\n\n";
            cout << "                                 LOGOUT\n\n";
            cout << "------------------------------------------------------------------------------------------------\n\n";
            cout << "are yoou sure to logout??\t press 'y' for yes \n";
            cin >> ch;
            if (ch == 'y' && 'y')
            {
                goto dash;
            }
            else
            {
                goto mainmenu;
            

        case 8:

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
            //ADD:*/

        }
	
	return 0;
}