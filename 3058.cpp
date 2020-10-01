#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int min_even = 100;
		int sum = 0;

		for (int i = 0; i < 7; i++) {
			int num;
			cin >> num;

			if (num % 2 == 0) {
				sum += num;
				min_even = min(min_even, num);
			}
		}

		cout << sum << ' ' << min_even << '\n';
	}

	return 0;
}