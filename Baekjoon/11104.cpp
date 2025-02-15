#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string binary_num;
		cin >> binary_num;

		int len = binary_num.length();
		unsigned int sum = 0;

		for (int i = 0; i < len; i++) {
			int x = len - (i + 1);
			sum += (int)(binary_num[i] - '0')*(int)pow(2, x);
		}

		cout << sum << '\n';
	}

	return 0;
}