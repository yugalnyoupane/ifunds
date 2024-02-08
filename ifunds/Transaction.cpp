#include "Transaction.h"
#include <iostream>
#include <string>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

using namespace std;

Transaction::Transaction() {
    recieverUsername = "null";
    recieverWallet_id = 0;
}
void Transaction::setRecieverUsername() {
    cout << "Enter reciever's username: ";
    cin >> recieverUsername;
}
    

void Transaction::setRecieverWallet_id() {
    cout << "Enter reciever's waller id: ";
    cin >> recieverWallet_id;
}

string Transaction::getRecieverUsername() {
    return recieverUsername;
}
/*int Transaction::getRecieverWallet_id() {
    return recieverWallet_id;
}*/

void Transaction::setTransactionAmount() {
    cout << "Enter the transaction amount: ";
    cin >> transactionAmount;
}
int Transaction::saveTransactionLog() {
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "quoriumesh");
        con->setSchema("ifunds");

        sql::Statement* stmt;
        wallet_id = 5;
        // Insert data
        string ctransactionAmount = to_string(transactionAmount);
        stmt = con->createStatement();
        stmt->executeUpdate("INSERT INTO TransactionLog(amount, sender, reciever) VALUES (" + ctransactionAmount + ", '" + username + "', '" + recieverUsername + "')");

        con->commit();

        cout << "-----------Transaction saved successfully----------" << endl;

        delete stmt;
        delete con;

    }
    catch (sql::SQLException& e) {
        cout << "Error saving transaction log:" << endl;
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "SQL State: " << e.getSQLState() << endl;
        return 1;
    }
    return 0;
}




int Transaction::initiateTransaction() {
    cout << "Enter the reciver details:"<<endl;
    setRecieverWallet_id();
    setRecieverUsername();



    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "quoriumesh");
        con->setSchema("ifunds");

        sql::Statement* stmt;
        sql::ResultSet* res;

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM info WHERE id =" + to_string(recieverWallet_id));

       
        while (res->next())
        {
            if (recieverUsername == res->getString("username")) {
                setTransactionAmount();

                cout<< "To confirm transaction enter your username:"<<endl;
                setUsername();

                
                stmt = con->createStatement();
                res = stmt->executeQuery("SELECT * FROM info WHERE id = 5");

                while (res->next()) {
                    if (transactionAmount <= res->getDouble("balance")) {
                        stmt = con->createStatement();
                         stmt->executeUpdate("UPDATE info SET balance = balance -" + to_string(transactionAmount)
                            + "WHERE  id = 5");

                        stmt = con->createStatement();                        
                            stmt->executeUpdate("UPDATE info SET balance = balance +" + to_string(transactionAmount)
                                + "WHERE  id =" + to_string(recieverWallet_id));

                        cout << "\n\t\t\t---------Transaction Complete---------";

                        saveTransactionLog();

                    }
                    else {
                        cout << "\n\t\t\t---------Insufficient Balance---------";
                    }
                }
            }
            else {
                cout << "\n\t\t\t---------Invalid reciever id or username----------";
            }

        }
        con->commit();
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Error making transaction because of the following reasons:" << endl;
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "SQL State: " << e.getSQLState() << endl;
        return 1;
    }
    return 0;
}
