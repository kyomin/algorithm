#include <iostream>
#include <string>

using namespace std;

int n, k;

int cnt = 0;

string result;
bool found;

void go(int curVal, int operand, string expression) {
	// 다른 곳에서 해답을 찾았으면 더 찾을 필요가 없다.
	if (found)
		return;
	
	if ((curVal + operand) == n) {
		expression = expression + "+" + to_string(operand);
		cnt++;

		if (cnt == k) {
			result = expression;
			found = true;
		}

		return;
	}

	if ((curVal + operand) > n)
		return;

	expression = expression + "+" + to_string(operand);

	go((curVal + operand), 1, expression);
	go((curVal + operand), 2, expression);
	go((curVal + operand), 3, expression);
}

int main() {
	cin >> n >> k;

	go(1, 1, "1");
	go(1, 2, "1");
	go(1, 3, "1");

	go(2, 1, "2");
	go(2, 2, "2");
	go(2, 3, "2");

	go(3, 1, "3");
	go(3, 2, "3");
	go(3, 3, "3");

	if (found)
		cout << result << '\n';
	else
		cout << -1 << '\n';

	return 0;
}