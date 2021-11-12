#include <iostream>
using namespace std;

int main() {
	while (true) {
		int balance, amount;
		char action;
		cin >> balance >> action >> amount;

		if (balance == 0 && action == 'W' && amount == 0)
			break;

		if (action == 'W') {
			int rest = balance - amount;

			if (rest < -200)
				cout << "Not allowed" << endl;
			else
				cout << rest << endl;
		}
		else {
			cout << balance + amount << endl;
		}
	}

	return 0;
}