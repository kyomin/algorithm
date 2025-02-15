#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string result = "";
	unsigned long N;
	cin >> N;

	while (N >= 2) {
		unsigned long r = N % 2;
		N = N / 2;

		result += (char)(r + '0');
	}

	result += (char)(N + '0');
	int len = result.size();
	int sum = 0;

	for (int i = 0; i < len; i++) {
		int x = len - (i + 1);

		sum += (int)(result[i] - '0')*(int)pow(2, x);
	}

	cout << sum << endl;

	return 0;
}