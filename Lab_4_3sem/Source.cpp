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
	void SetLogin(string l) { login = l; }
	void SetPassword(string p) { password = p; }
	string GetLogin() { return login; }
	string GetPassword() { return password; }
	int GetBalance() { return balance; }
	void SetBalance(int value) { balance = value; }
};

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

void replenishment(BankAccount &acc) {
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

void debiting(BankAccount &acc) {
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

int main() {
	BankAccount user("USER1", "123456");
	BankAccount user2("USER2", "qwerty");
	BankAccount user3("USER3", "russia_on_the_top");
	BankAccount logined_user;
	vector <BankAccount> users = { user, user2, user3 };

	string input_login = "", input_password = "";

	cout << "Enter username: ";
	getline(cin, input_login);
	cout << "Enter password: ";
	getline(cin, input_password);
	
	bool account_found = false, logined = false;
	for (auto x : users) {
		if (x.GetLogin() == input_login && x.GetPassword() == input_password) {
			logined_user = x;
			account_found = true;
			break;
		}
	}
	while (true) {
		if (account_found) {
			if (!logined) {
				cout << "You have successfully logged into your bank account, " << logined_user.GetLogin() << ".\n";
				logined = true;
			}
			cout << "What kind of account operation would you like to perform?\n";
			cout << "1) Top up your account balance;\n2) Debiting money from the account;\n3) Log out.\n";
			cout << "Your choice: ";
			int num;
			cin >> num;
			cout << "\n";
			switch (num) {
			case 1:
				replenishment(logined_user);
				break;
			case 2:
				debiting(logined_user);
				break;
			case 3:
				exit(1);
			}
			cout << logined_user.GetBalance();
		}
		else {
			cout << "Invalid username or password. Try logging in again.\n";
			cout << "Enter username: ";
			getline(cin, input_login);
			cout << "Enter password: ";
			getline(cin, input_password);
		}
	}
}



