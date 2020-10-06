#include <iostream>

using namespace std;

int solution(int n) {
	int ans = 0;

	if (n == 1)
		return 1;

	while (n > 1) {
		int q = n / 2;
		int r = n % 2;

		if (r == 1)
			ans += 1;

		if (q == 1) {
			ans += 1;
			break;
		}

		n /= 2;
	}

	return ans;
}