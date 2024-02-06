#pragma once
#include<iostream>
#include<string>

using namespace std;
class User
{
protected:
	std::string username, password;
	int wallet_id;

public:
	User();
	User(string username, string password, int wallet_id );
	string getUsername();
	string gatPassword();
	int getWallet_id();
	void setUsername();
	void setPassword();
	void setWallet_id(int wallet_id);
	};

