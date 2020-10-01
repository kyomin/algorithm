#include <iostream>
#include <string>

using namespace std;

string solution(string n) {
	// 한 자리 수가 아닐 때까지
	while (n.size() != 1) {
		int len = n.size();

		int sum = 0;

		for (int i = 0; i < len; i++)
			sum += (int)(n[i] - '0');

		n = to_string(sum);
	}

	return n;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		string n;
		cin >> n;

		if (n == "0")
			break;

		cout << solution(n) << '\n';
	}

	return 0;
}