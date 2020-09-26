#include <iostream>

using namespace std;

// 연산에 의해 N -> 1로 가는 최소 횟수
int solution(int N) {
	int ans = 0;

	while (true) {
		if (N == 1)
			break;

		int count_one = 0;

		while (N > 1) {
			int q = N / 2;
			int r = N % 2;

			N /= 2;

			if (r == 1)
				count_one++;
		}

		N = count_one + 1;
		ans++;
	}

	return ans;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		int LO, HI, X;
		cin >> LO >> HI >> X;

		if (LO == 0 && HI == 0 && X == 0)
			break;

		int ans = 0;

		for (int N = LO; N <= HI; N++) {
			if (solution(N) == X)
				ans++;
		}

		cout << ans << '\n';
	}

	return 0;
}