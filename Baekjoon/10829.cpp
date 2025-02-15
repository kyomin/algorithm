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

	reverse(result.begin(), result.end());

	cout << result << endl;

	return 0;
}