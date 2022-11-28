#include "BankAccount.h"

int main() {
	BankAccount user("USER1", "123456");
	BankAccount user2("USER2", "qwerty");
	BankAccount user3("USER3", "russia_on_the_top");
	BankAccount logined_user;
	vector <BankAccount> users = { user, user2, user3 };

	string met_str = "";
	int method;
	cout << "Choose the method of working with parameters:\n";
	cout << "1) Get/Set;\n2) Friendly.\n";
	getline(cin, met_str);
	method = check_str(met_str);
	while (method < 1 || method > 2) {
		cout << "\nChoose the method of working with parameters:\n";
		cout << "1) Get/Set;\n2) Friendly.\n";
		getline(cin, met_str);
		method = check_str(met_str);
	}

	string input_login = "", input_password = "";

	cout << "Enter username: ";
	getline(cin, input_login);
	cout << "Enter password: ";
	getline(cin, input_password);
	if (input_login[input_login.length() - 1] == ' ') {
		int i = input_login.length() - 1;
		while (input_login[i] == ' ') {
			input_login.erase(i);
			i--;
		}
	}
	if (input_password[input_password.length() - 1] == ' ') {
		int i = input_password.length() - 1;
		while (input_password[i] == ' ') {
			input_password.erase(i);
			i--;
		}
	}

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
				if (method == 1) replenishment(logined_user);
				else replenishment_friendly(logined_user);
				break;
			case 2:
				if (method == 1) debiting(logined_user);
				else debiting_friendly(logined_user);
				break;
			case 3:
				exit(1);
			}
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



