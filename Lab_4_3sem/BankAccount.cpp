#include "BankAccount.h"

void BankAccount::SetLogin(string l) { login = l; }
void  BankAccount::SetPassword(string p) { password = p; }
string  BankAccount::GetLogin() { return login; }
string  BankAccount::GetPassword() { return password; }
int  BankAccount::GetBalance() { return balance; }
void  BankAccount::SetBalance(int value) { balance = value; }

int check_str(string const& str) {
	int val = 0;
	for (int i = 0; i < str.length(); i++) {
		if ('0' <= str[i] && str[i] >= '9') {
			return 0;
		}
		val *= 10;
		val += str[i] - '0';
	}
	return val;
}

void replenishment_friendly(BankAccount& acc) {
	cout << "The deposit amount should not exceed 100,000 at a time. Enter the deposit amount: ";
	string string_value;
	getline(cin, string_value);

	int value = check_str(string_value);

	while (value < 1 || value > 100000) {
		cout << "Incorrect amount entered (minimum - 1, maximum - 100,000). Enter the deposit amount: ";
		string_value = "";
		getline(cin, string_value);
		value = check_str(string_value);
	}
	acc.balance += value;
	cout << "Replenishment was successful. Your current balance is " << acc.balance << ".\n\n";
}
void debiting_friendly(BankAccount& acc) {
	if (acc.GetBalance() == 0) {
		cout << "You have zero balance.\n";
		return;
	}
	cout << "Enter the amount to be debited from the account: ";
	string string_value;
	getline(cin, string_value);

	int value = check_str(string_value);

	while (value < 1 || acc.balance - value < 0) {
		cout << "Incorrect amount entered (minimum - 1, maximum - " << acc.balance << "). Enter the deposit amount : ";
		string_value = "";
		getline(cin, string_value);
		value = check_str(string_value);
	}
	acc.SetBalance(acc.balance - value);
	cout << "Replenishment was successful. Your current balance is " << acc.balance << ".\n\n";
}

void replenishment(BankAccount& acc) {
	cout << "The deposit amount should not exceed 100,000 at a time. Enter the deposit amount: ";
	string string_value;
	getline(cin, string_value);

	int value = check_str(string_value);

	while (value < 1 || value > 100000) {
		cout << "Incorrect amount entered (minimum - 1, maximum - 100,000). Enter the deposit amount: ";
		string_value = "";
		getline(cin, string_value);
		value = check_str(string_value);
	}
	acc.SetBalance(acc.GetBalance() + value);
	cout << "Replenishment was successful. Your current balance is " << acc.GetBalance() << ".\n\n";
}
void debiting(BankAccount& acc) {
	if (acc.GetBalance() == 0) {
		cout << "You have zero balance.\n";
		return;
	}
	cout << "Enter the amount to be debited from the account: ";
	string string_value;
	getline(cin, string_value);

	int value = check_str(string_value);

	while (value < 1 || acc.GetBalance() - value < 0) {
		cout << "Incorrect amount entered (minimum - 1, maximum - " << acc.GetBalance() << "). Enter the deposit amount : ";
		string_value = "";
		getline(cin, string_value);
		value = check_str(string_value);
	}
	acc.SetBalance(acc.GetBalance() - value);
	cout << "Replenishment was successful. Your current balance is " << acc.GetBalance() << ".\n\n";
}

