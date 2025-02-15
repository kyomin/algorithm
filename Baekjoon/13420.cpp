#include <iostream>
using namespace std;

long long operate(long long a, long long b, char oper) {
	if (oper == '+')
		return a + b;
	else if (oper == '-')
		return a - b;
	else if (oper == '*')
		return a * b;
	else
		return a / b;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		long long a, b, ans;
		char oper, equal;
		cin >> a >> oper >> b >> equal >> ans;

		if (operate(a, b, oper) == ans)
			cout << "correct" << endl;
		else
			cout << "wrong answer" << endl;
	}

	return 0;
}