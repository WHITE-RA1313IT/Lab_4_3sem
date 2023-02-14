#include "BankAccount.h"

void BankAccount::SetLogin(string l) { login = l; }
void  BankAccount::SetPassword(string p) { password = p; }
string  BankAccount::GetLogin() { return login; }
string  BankAccount::GetPassword() { return password; }
int  BankAccount::GetBalance() { return balance; }
void  BankAccount::SetBalance(int value) { balance = value; }

int ReadInt() {
	string val;
	cin.clear();
	getline(cin, val);

	if (val == "" || val.length() > 9) {
		cout << "\nERROR: Incorrect input. You entered a text, not a number. (Text is automatically detected from 10 characters)\n\n";
		return 0;
	}
	for (int i = 0; i < val.length(); i++) {
		if (i == 0 && val[i] == '-') continue;
		if (val[i] < '0' || val[i] > '9') {
			cout << "\nERROR: Incorrect input. You entered a text, not a number. (Text is automatically detected from 10 characters)\n\n";
			return 0;
		}
	}
	return stoi(val);
}

bool CheckString(string const& str) {
	for (int i = 0; i < str.length(); i++) {
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == '_')) return false;
	}
	return true;
}

void replenishment_friendly(BankAccount& acc) {
	cout << "The deposit amount should not exceed 100,000 at a time. Enter the deposit amount: ";

	int value = ReadInt();

	while (value < 1 || value > 100000) {
		cout << "Incorrect amount entered (minimum - 1, maximum - 100,000). Enter the deposit amount: ";
		value = ReadInt();
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

	int value = ReadInt();

	while (value < 1 || acc.balance - value < 0) {
		cout << "Incorrect amount entered (minimum - 1, maximum - " << acc.balance << "). Enter the deposit amount : ";
		value = ReadInt();
	}
	acc.SetBalance(acc.balance - value);
	cout << "Replenishment was successful. Your current balance is " << acc.balance << ".\n\n";
}

void replenishment(BankAccount& acc) {
	cout << "The deposit amount should not exceed 100,000 at a time. Enter the deposit amount: ";
	
	int value = ReadInt();

	while (value < 1 || value > 100000) {
		cout << "Incorrect amount entered (minimum - 1, maximum - 100,000). Enter the deposit amount: ";
		value = ReadInt();
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

	int value = ReadInt();

	while (value < 1 || acc.GetBalance() - value < 0) {
		cout << "Incorrect amount entered (minimum - 1, maximum - " << acc.GetBalance() << "). Enter the deposit amount : ";
		value = ReadInt();
	}
	acc.SetBalance(acc.GetBalance() - value);
	cout << "Replenishment was successful. Your current balance is " << acc.GetBalance() << ".\n\n";
}