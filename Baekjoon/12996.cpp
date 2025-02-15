#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

unsigned long long d[51][51][51][51];

unsigned long long go(int N, int i, int j, int k) {
	if (N == 0) {
		if (i == 0 && j == 0 && k == 0)
			return 1;
		else
			return 0;
	}

	unsigned long long &ans = d[N][i][j][k];

	// 이미 해가 구해진 경우라면
	if (ans != -1)
		return ans;

	ans = 0;

	// 7가지 경우의 수 모두 구해보자
	if (i - 1 >= 0)
		ans += go(N - 1, i - 1, j, k);
	if (j - 1 >= 0)
		ans += go(N - 1, i, j - 1, k) % 1000000007;
	if (k - 1 >= 0)
		ans += go(N - 1, i, j, k - 1) % 1000000007;
	if (i - 1 >= 0 && j - 1 >= 0)
		ans += go(N - 1, i - 1, j - 1, k) % 1000000007;
	if (j - 1 >= 0 && k - 1 >= 0)
		ans += go(N - 1, i, j - 1, k - 1) % 1000000007;
	if (i - 1 >= 0 && k - 1 >= 0)
		ans += go(N - 1, i - 1, j, k - 1) % 1000000007;
	if (i - 1 >= 0 && j - 1 >= 0 && k - 1 >= 0)
		ans += go(N - 1, i - 1, j - 1, k - 1) % 1000000007;

	return ans % 1000000007;
}

int main() {
	memset(d, -1, sizeof(d));

	int S, a, b, c;
	cin >> S >> a >> b >> c;

	cout << go(S, a, b, c) << '\n';

	return 0;
}