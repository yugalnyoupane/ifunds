#include<iostream>
#include<string>
#include"User.h"

using namespace std;

User::User() {
	username = "null";
	password = "null";
	wallet_id = 0;
}

User::User(string username, string password, int wallet_id):
			username(username), password(password), wallet_id(wallet_id){}


string User::getUsername() { 
	return username; }

string User::gatPassword() {
	return password;
}

int User::getWallet_id() {
	return wallet_id;
}

void User::setUsername(string username) {
	this->username = username;
}

void User::setPassword(string password) {
	this->password = password;
}

void User::setWallet_id(int wallet_id) {
	this->wallet_id = wallet_id;
}