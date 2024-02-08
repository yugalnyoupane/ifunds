#include "account.h"
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
extern sql::Statement* stmt;
extern sql::ResultSet* res;

void account::get_currency_name()
{
    string tempname;
    int tempnum;
    cout << "\nEnter SN  of currency from the table:\n\n ";
    res = stmt->executeQuery("select *  from currency_rate ");
    cout <<"CURRENCY NAME:" << "\t\t\t\t\t"<< "Symbol Number:" << "\n";
    while (res->next())
    {
        tempname = res->getString("currency_name");
        tempnum = res->getInt("SN");
       
        cout << tempname<<"\t\t-----------\t\t";
        cout << tempnum << "\n";
    }
    cout << "\nENTER HERE FROM  WHICH CURRENCY :\t";
    cin >> currencyname1;
    cout << "ENTER HERE TO WHICH CURRENCY :\t";
    cin >> currencyname2;
}
void account::convert_currency()
{
    int temprate1,temprate2 , amount_to_convert;
    float converted_amount; 
    string symbol1,symbol2;
    res = stmt->executeQuery("select rate,symbol  from currency_rate where SN = '" + currencyname1 + "' "); //to get rate from currency name of from wala

    while (res->next())
    {
        
         temprate1= res->getInt("rate");
         symbol1= res->getString("symbol");
         cout << "Rate of "<<symbol1<<" according to NPR is:\t" << temprate1<<"\n";
    }

    res = stmt->executeQuery("select rate,symbol  from currency_rate where SN = '" + currencyname2 + "' "); //to get rate from currency name of to wala

    while (res->next())
    {

        temprate2= res->getInt("rate");
        symbol2 = res->getString("symbol");
        cout << "Rate of " << symbol2<<" according to NPR is:\t" << temprate2;
    }
    cout << "\n ENTER HOW MUCH MONEY TO CONVERT :\t";
    cin >> amount_to_convert;


    converted_amount = (float(amount_to_convert)*float(temprate1))/float(temprate2);
    cout << "The conversion is FROM: " << symbol1 << " TO: " << symbol2 << "\n";
    cout << "\n Converted Amount is:\t" << converted_amount<<"\t"<<symbol2;
}
int account::confirmcurrency()
{

    try
    {

        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://:3306", "sqluser", "password");
        stmt = con->createStatement();
        stmt->execute("CREATE DATABASE IF NOT EXISTS IFUNDs"); // CREATES DATABASE
        con->setSchema("IFUNDs"); // CALLS DATABASE


        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                  CURRENCY CONVERTER\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
    
     get_currency_name();
     convert_currency();
   
    delete res;
    delete stmt;
    delete con;

    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "SQL State: " << e.getSQLState() << endl;
        return 1;
    }

    return 0;
}

void account::deposit()
{
    int temp_mpin=0;
    cout << "\nenter amount you want to deposit:\t";
    cin >> amount;
    if (amount >= 10)
    {
        string tempusername;
        cout << "\nenter username:\t";
        cin >> tempusername; 
        cout << "\nenter mpin:\t";
        cin >> temp_mpin;
        
        res = stmt->executeQuery("SELECT mpin FROM info WHERE name='" + tempusername + "' ");
        while (res->next())
        {
           
            if (temp_mpin == res->getInt("mpin")) {

                stmt->executeUpdate("UPDATE info SET balance = balance +" + to_string(amount)
                    + "WHERE  name='" + tempusername + "'");
                cout << "\n\t\t\t---------Deposit Complete---------";
            }
            else
            {
                cout << "\n mpin doesnot match the user!!!";

            }
        }
    }
    else
    { 
        cout << "\nenter amount greate than 10!";
    }
   
}
int account::confirmdeposit()
{
    try
    {

        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

         driver = sql::mysql::get_mysql_driver_instance();
         con = driver->connect("tcp://:3306", "sqluser", "password");
         stmt = con->createStatement();
         stmt->execute("CREATE DATABASE IF NOT EXISTS IFUNDs"); // CREATES DATABASE
         con->setSchema("IFUNDs"); // CALLS DATABASE
         


        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                  deposit money\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        deposit();
        

        
    }
    catch (sql::SQLException& e) 
    {
        cout << "Error making deposit because of the following reasons:" << endl;
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "SQL State: " << e.getSQLState() << endl;
    }
    return 0;
}

void account::withdraw()
{
    int temp_mpin = 0;
    cout << "\nenter amount you want to withdraw:\t";
    cin >> amount;
    if (amount >= 10)
    {
        string tempusername;
        cout << "\nenter username:\t";
        cin >> tempusername;
        cout << "\nenter mpin:\t";
        cin >> temp_mpin;

        res = stmt->executeQuery("SELECT mpin FROM info WHERE name='" + tempusername + "' ");
        while (res->next())
        {
           
            if (temp_mpin == res->getInt("mpin")) {

                stmt->executeUpdate("UPDATE info SET balance = balance -" + to_string(amount)
                    + "WHERE  name='" + tempusername + "'");
                cout << "\n\t\t\t---------Withdraw Complete---------";
            }
            else
            {
                cout << "\n mpin doesnot match the user!!!";

            }
        }
    }
    else
    {
        cout << "\nenter amount greate than 10!";
    }

}
int account::confirm_withdraw()
{
    try
    {

        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://:3306", "sqluser", "password");
        stmt = con->createStatement();
        stmt->execute("CREATE DATABASE IF NOT EXISTS IFUNDs"); // CREATES DATABASE
        con->setSchema("IFUNDs"); // CALLS DATABASE



        cout << "------------------------------------------------------------------------------------------------\n\n";
        cout << "                                  withdraw money\n\n";
        cout << "------------------------------------------------------------------------------------------------\n\n";
        withdraw();
       


    }
    catch (sql::SQLException& e)
    {
        cout << "Error making withdraw because of the following reasons:" << endl;
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "SQL State: " << e.getSQLState() << endl;
    }
    return 0;
}