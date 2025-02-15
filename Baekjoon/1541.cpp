#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> operands;
string expression;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> expression;

	int len = expression.size();

	string num = "";
	int operand = 0;

	for (int i = 0; i < len; i++) {
		// 숫자라면
		if (isdigit(expression[i])) {
			num += expression[i];
			continue;
		}

		// + 기호를 만나면 계속 더해준다.
		if (expression[i] == '+') {
			operand += atoi(num.c_str());
			num = "";
			continue;
		}

		// - 기호를 만나면 operands에 추가!
		if (expression[i] == '-') {
			operand += atoi(num.c_str());
			num = "";
			operands.push_back(operand);
			operand = 0;
			continue;
		}
	}

	operand += atoi(num.c_str());
	operands.push_back(operand);

	len = operands.size();
	int result = operands[0];

	for (int i = 1; i < len; i++)
		result -= operands[i];

	cout << result << '\n';

	return 0;
}