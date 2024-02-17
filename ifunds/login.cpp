#include <iostream>
#include <string>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

using namespace std;

const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "";

class Login {
private:
	string Id, PW;
public:
	Login():Id(""),PW(""){   }

	void setId(string id) {
		Id = id;
	}
	void setPW(string pw) {
		PW = pw;
	}

	string getId() {
		return Id;
	}
	string getPW() {
		return PW;
	}
};
map<string, int> unsuccessfulAttempts;
int main() {

	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;

	try {
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		con->setSchema("user_id");

		Login l;
		string username, password;
		bool validLogin = false;
		while (!validLogin) {
			cout << "Enter your username: ";
			cin >> username;
			l.setId(username);
			if (unsuccessfulAttempts[username] >= 5) {
				cout << "Maximum login attempts exceeded for this user." << endl;
				return 0; // Exit the program
			}

			cout << "Enter your password: ";
			cin >> password;
			l.setPW(password);

			stmt = con->createStatement();
			res = stmt->executeQuery("SELECT * FROM login_detail WHERE username='" + username + "'AND password='" + password + "'");

			if (res->next()) {
				cout << "Login successful. Welcome, " << res->getString("username") << "!" << endl;
				validLogin = true;
			}
			else {
				cout << "Invalid username or password." << endl;
				// Increment the unsuccessful attempts counter for this user
				unsuccessfulAttempts[username]++;
			}
			delete res;
			delete stmt;
		}
		delete con;
	}

	catch (sql::SQLException e)
	{
		cout << "Couldn't connect to server. Error message. " << e.what() << endl;
		system("pause");
		exit(1);
	}

	return 0;

}
