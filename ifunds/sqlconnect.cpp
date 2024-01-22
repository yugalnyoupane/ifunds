#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "quoriumesh");

        con->setSchema("ifunds");

        sql::Statement* stmt;

        // Insert data
        stmt = con->createStatement();
        stmt->execute("INSERT INTO info (id, name, age) VALUES (1,'John Doe', 25)");
        con->commit();

        delete stmt;
        delete con;

        cout << "Data inserted successfully." << endl;

    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
        cerr << "SQL State: " << e.getSQLState() << endl;
        return 1;
    }

    return 0;
}