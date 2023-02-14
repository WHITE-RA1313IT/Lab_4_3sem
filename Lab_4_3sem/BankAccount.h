#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
	string login, password;
	int balance = 0;
public:
	BankAccount() {
		login = "";
		password = "";
	}
	BankAccount(string l, string p) {
		login = l;
		password = p;
	}
	void SetLogin(string l);
	void SetPassword(string p);
	string GetLogin();
	string GetPassword();
	int GetBalance();
	void SetBalance(int value);

	friend void replenishment_friendly(BankAccount& acc);
	friend void debiting_friendly(BankAccount& acc);
};

void replenishment(BankAccount& acc);

void debiting(BankAccount& acc);

int ReadInt();
bool CheckString(string const& str);