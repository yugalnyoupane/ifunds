#include <iostream>
#include<string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include "DeleteAccount.h"

using namespace std;
DeleteAccount::DeleteAccount() {
    tempUsername = "null";
    tempPassword = "null";
}

void DeleteAccount::setTempUsername() {
    cout << "Enter your username: ";
    cin >> tempUsername;
}

void DeleteAccount::setTempPassword() {
    cout << "Enter your password: ";

    cin >> tempPassword;
}

int DeleteAccount::confirmDeletion(){
        
    cout << "Please comfirm your deletion by entering your username and password" << endl;
    setTempUsername();
    setTempPassword();

    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "quoriumesh");
        con->setSchema("ifunds");

        sql::Statement* stmt;
        sql::ResultSet* res;
        wallet_id = 1;
        // Select data
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM info WHERE id =" + to_string(wallet_id));



        while (res->next())
        {
            username = res->getString("username"), password = res->getString("password");
        }

        if (username == tempUsername && password == tempPassword)
        {
            // Delete data
            stmt = con->createStatement();
            stmt->execute("DELETE FROM info WHERE id =" + to_string(wallet_id));

            delete res;
            delete stmt;
            delete con;

            cout << "\n\t\t\t----------Account deleted successfully.----------" << endl;

        }
        else {
            cout << "\n\t\t\t----------Invalid username or password----------";
        }
    }
    catch (sql::SQLException& e) {
        cout << "Error deleting your account because of the following reasons:" << endl;
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "SQL State: " << e.getSQLState() << endl;
        return 1;
    }


    
    return 0;
}

