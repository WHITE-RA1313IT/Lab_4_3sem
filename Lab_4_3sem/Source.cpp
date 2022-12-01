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

	while (true) {
		string input_login = "", input_password = "";

		cout << "\nSelect an action:\n";
		cout << "1) Registration;\n2) Log in;\n3) Exit.\n";
		string rle_str = "";
		int reg_log_ex;
		getline(cin, rle_str);
		reg_log_ex = check_str(rle_str);

		while (method < 1 || method > 3) {
			cout << "\nSelect an action:\n";
			cout << "1) Registration;\n2) Log in;\n3) Exit.\n";
			getline(cin, rle_str);
			method = check_str(rle_str);
		}

		switch (reg_log_ex)
		{
		case 1:
		{
			bool registered = false;
			while (!registered) {
				cout << "Enter username: ";
				getline(cin, input_login);
				cout << "Enter password: ";
				getline(cin, input_password);
				del_spaces(input_login);
				del_spaces(input_password);

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
				else cout << "An account with this name has already been registered.\n\n";
			}
		}
		break;
		case 2:
		{
			bool account_found = false;
			while (!account_found) {
				cout << "\nEnter username: ";
				getline(cin, input_login);
				cout << "Enter password: ";
				getline(cin, input_password);
				del_spaces(input_login);
				del_spaces(input_password);

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
				cin >> num;
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
					cin.get();
					break;
				}
			}
			break;
		}
		case 3:
		{
			exit(1);
			break;
		}
		}
	}
}



