#include <iostream>
#include<string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include"user.h"
#include "DeleteAccount.h"

using namespace std;
int main() {


    DeleteAccount delete_account;

    delete_account.confirmDeletion();




    return 0;
}