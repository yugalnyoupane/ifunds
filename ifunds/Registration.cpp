#include "Registration.h"
#include<iostream>
#include <string.h>
#include<conio.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std;
using namespace std::chrono;
sql::Statement* stmt;
sql::ResultSet* res;

void Registration::get_data()
{
    cout << "enter your username:\t";
    cin >> username;
again:
    cout << "enter your age:\t";
    cin >> age;
    if (age > 0 && age < 100) // check to see for 2 digits
    {
        goto next;
    }
    else
    {
        cout << "age  must be of 2 digits!!\n";
        goto again;
    }
next:
    cout << "enter your email in abc@gmail.com format:\t";
    cin >> email;
    cout << "enter your password:\t";
    char ch = _getch();
    while (ch != 13)
    {//character 13 is enter
        if (ch == 8)
        {
            if (password.size() > 0) {
                password.erase(password.size() - 1, 1);
                cout << "\b \b";
            }
        }
        else {
            password.push_back(ch);
            cout << '*';

        }
        ch = _getch();
    }
    cout << "\n";


enteragain: //label
    cout << "enter your transcation pin(mpin) of four digits: \t";
    cin >> mpin;
    if (mpin > 999 && mpin < 10000) // check to see for 4 digits
    {
        goto pass;
    }
    else
    {
        cout << "mpin must be of 4 digits!!";
        goto enteragain;
    }
pass: //label
    string cage = to_string(age); //int to string cause of database issue
    string cmpin = to_string(mpin);

    string query = "INSERT INTO info (name,age,email,password,mpin) VALUES ('" + username + "','" + cage + "', '" + email + "', '" + password + "','" + cmpin + "')"; // inserts into database
    stmt->execute(query);
}

void Registration::get_user_id()
{

    // selects id from database
    res = stmt->executeQuery("select id  from info where name =  '" + username + "' ");

    while (res->next())
    {
        cout << "\n your ifunds Id is:\t" << res->getInt("id");
    }

}

int Registration::confirm_registration()
{

    try
    {

        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "quoriumesh");
        con->setSchema("ifunds");
        stmt = con->createStatement();
       //stmt->execute("CREATE DATABASE IF NOT EXISTS IFUNDs"); // CREATES DATABASE
        //con->setSchema("IFUNDs"); // CALLS DATABASE

        stmt->execute("CREATE TABLE IF NOT EXISTS info( id int auto_increment, name text(255), age int not null, email text(255), password text(255), mpin int not null, unique KEY (ID),PRIMARY KEY (name(255)) )"); // CREATES TABLE

        //dashboard
        int a; //for choice FOR DASHBOARD
        int b; // for choice for main menu

    dash:
        system("cls");
        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                      WELCOME TO IFUNDS!!!\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "-------------------------------------------*DASHBOARD*------------------------------------------\n\n\n";
        cout << " enter 1 for registration\n";
        cout << " enter 2 for login\n";
        cout << " enter 3 for forgot password\n";
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

        default:
            cout << "choose from the above options:\n";
            goto dash;
        }


        //registration platform
    regis:

        Registration r;
        r.get_data();  //gets data from user
        cout << "registered sucessufully:\n";
        r.get_user_id();
        cout << "\n returning to dashboard.........";

        sleep_for(seconds(3));//  add delay for nanoseconds, system_clock, seconds

        //goto dash;
        // after dashboard
    //faceauthentication:
        // after face authentication: 
        system("cls");


    /* mainmenu:
        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                      WELCOME TO MAIN MENU!!!\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n\n";
        cout << " enter 1 to add funds\n";
        cout << " enter 2 for transaction history\n";
        cout << " enter 3 to initiate transaction\n";
        cout << " enter 4 for account management\n";
        cout << " enter 5 for currency convertern\n";
        cout << " enter 6 to log out\n";
        cout << " enter 7 to exit \n";
        cout << "------------------------------------------------------------------------------------------------\n\n\n";

        cout << "enter your choice:\t";
        cin >> b;
        cout << "*********************************************************************************************************************\n\n";

        system("cls");
        switch (b)
        {
        case 1:


            cout << "------------------------------------------------------------------------------------------------\n\n";
            cout << "                                 WELCOME TO ADD FUNDS\n\n";
            cout << "------------------------------------------------------------------------------------------------\n\n";
            //goto ADD;
        case 2:
        case 6:
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
            }

        case 7:

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
            //ADD:
        }*/

    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "SQL State: " << e.getSQLState() << endl;
        return 1;
    }

    return 0;
}