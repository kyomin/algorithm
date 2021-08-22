#include <iostream>

using namespace std;

int main() {
	int cnt = 0;
	char oper;
	int operand;
	int result;
	cin >> result;

	while (true) {
		if (cnt % 2 == 0) {
			cin >> oper;

			if (oper == '=')
				break;
		}
		else {
			cin >> operand;

			if (oper == '+')
				result += operand;
			else if (oper == '-')
				result -= operand;
			else if (oper == '*')
				result *= operand;
			else if (oper == '/')
				result /= operand;
		}

		cnt++;
	}

	cout << result << endl;

	return 0;
}