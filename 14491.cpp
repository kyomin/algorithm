#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	string result = "";

	while (N >= 9) {
		result += to_string(N % 9);
		N /= 9;
	}

	result += to_string(N);

	reverse(result.begin(), result.end());

	cout << result << '\n';

	return 0;
}