#include "BankAccount.h"

int main() {
    BankAccount user("USER1", "123456");
	BankAccount user2("USER2", "qwerty");
	BankAccount user3("USER3", "russia_on_the_top");
	BankAccount logined_user;
	vector <BankAccount> users = { user, user2, user3 };

	cout << "Choose the method of working with parameters:\n";
	cout << "1) Get/Set;\n2) Friendly.\n";

	int method;
	method = ReadInt();

	while (method < 1 || method > 2) {
		cout << "\nChoose the method of working with parameters:\n";
		cout << "1) Get/Set;\n2) Friendly.\n";
		method = ReadInt();
	}

	while (true) {
		string input_login = "", input_password = "";

		cout << "\nSelect an action:\n";
		cout << "1) Registration;\n2) Log in;\n3) Exit.\n";
		int reg_log_ex;
		reg_log_ex = ReadInt();

		while (reg_log_ex < 1 || reg_log_ex > 3) {
			cout << "\nSelect an action:\n";
			cout << "1) Registration;\n2) Log in;\n3) Exit.\n";
			reg_log_ex = ReadInt();
		}

		switch (reg_log_ex) {
		case 1:
		{
			bool registered = false;
			while (!registered) {
				cout << "\nEnter username: ";
				getline(cin, input_login);
				if (!CheckString(input_login)) {
					cout << "\nIncorrect input. It is necessary to enter characters in the following ranges ('A' - 'Z', 'a' - 'z', '0' - '9', '_').\n";
					break;
				}

				cout << "Enter password: ";
				getline(cin, input_password);
				if (!CheckString(input_password)) {
					cout << "\nIncorrect input. It is necessary to enter characters in the following ranges ('A' - 'Z', 'a' - 'z', '0' - '9', '_').\n";
					break;
				}

				bool clear_acc = true;
				for (auto x : users) {
					if (x.GetLogin() == input_login) {
						clear_acc = false;
						break;
					}
				}
				if (clear_acc) {
					users.push_back(BankAccount(input_login, input_password));
					registered = true;
				}
				else cout << "An account with this name has already been registered.\n";
			}
		}
		break;
		case 2:
		{
			bool account_found = false;
			while (!account_found) {
				cout << "\nEnter username: ";
				getline(cin, input_login);
				if (!CheckString(input_login)) {
					cout << "\nIncorrect input. It is necessary to enter characters in the following ranges ('A' - 'Z', 'a' - 'z', '0' - '9', '_').\n";
					continue;
				}

				cout << "Enter password: ";
				getline(cin, input_password);
				if (!CheckString(input_password)) {
					cout << "\nIncorrect input. It is necessary to enter characters in the following ranges ('A' - 'Z', 'a' - 'z', '0' - '9', '_').\n";
					continue;
				}

				for (auto x : users) {
					if (x.GetLogin() == input_login && x.GetPassword() == input_password) {
						logined_user = x;
						account_found = true;
						break;
					}
				}
				if (account_found) cout << "You have successfully logged into your bank account, " << logined_user.GetLogin() << ".\n\n";
				else cout << "Invalid username or password. Try logging in again.";
			}

			while (true) {
				cout << "What kind of account operation would you like to perform?\n";
				cout << "1) Top up your account balance;\n2) Debiting money from the account;\n3) Log out.\n";
				cout << "Your choice: ";
				int num;
				num = ReadInt();
				cout << "\n";
				if (num == 1) {
					if (method == 1) replenishment(logined_user);
					else replenishment_friendly(logined_user);
				}
				if (num == 2) {
					if (method == 1) debiting(logined_user);
					else debiting_friendly(logined_user);
				}
				if (num == 3) {
					break;
				}
			}
			break;
		}
		case 3:
		{
			exit(0);
			break;
		}
		}
	}
}



