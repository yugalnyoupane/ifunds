#include<iostream>
#include"user.h"
#include"DeleteAccount.h"
#include "Registration.h"

int main() {
	Registration registers;
	registers.confirm_registration();
	DeleteAccount delete_account;
	delete_account.confirmDeletion();
	return 0;
}