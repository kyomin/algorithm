#include <iostream>
#include <string>

using namespace std;

int main() {
	string num1, num2;
	char oper;
	cin >> num1;
	cin >> oper;
	cin >> num2;

	if (oper == '*') {
		for (int i = 0; i < num2.size() - 1; i++)
			num1 += "0";

		cout << num1 << '\n';
	}

	if (oper == '+') {
		if (num1.size() > num2.size()) {
			int idx = num1.size() - num2.size();

			num1[idx] = '1';

			cout << num1 << '\n';
		}
		else if(num1.size() < num2.size()) {
			int idx = num2.size() - num1.size();

			num2[idx] = '1';

			cout << num2 << '\n';
		}
		else {
			num1[0] = '2';

			cout << num1 << '\n';
		}
	}

	return 0;
}