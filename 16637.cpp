#include <iostream>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

const int MIN = numeric_limits<int>::min();

int n, max_ans;
string str;

int cal(int a, int b, char oper) {
	int result = a;

	switch (oper) {
	case '+': 
		result += b;
		break;

	case '*':
		result *= b;
		break;

	case '-':
		result -= b;
		break;
	}

	return result;
}

void recur(int idx, int cur_val) {
	// 1. 종료 조건
	if (idx >= n) {
		max_ans = max(max_ans, cur_val);
		return;
	}

	char oper = (idx == 0) ? '+' : str[idx - 1];

	// 2. 괄호로 묶는다 => 이전 + 괄호 계산
	if (idx + 2 < n) {
		int bracket = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		recur(idx + 4, cal(cur_val, bracket, oper));
	}

	// 3. 안 묶는다 => 이전 + 다음
	recur(idx + 2, cal(cur_val, str[idx] - '0', oper));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> str;

	max_ans = MIN;
	recur(0, 0);
	cout << max_ans << '\n';

	return 0;
}