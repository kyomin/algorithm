#include <iostream>
#include <algorithm>

using namespace std;

int max_val;

int solution(int n) {
	max_val = max(max_val, n);

	if (n == 1)
		return max_val;

	return n % 2 == 0 ? solution(n / 2) : solution(3 * n + 1);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		max_val = n;
		cout << solution(n) << '\n';
	}

	return 0;
}