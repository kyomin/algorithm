#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
using ll = long long;

int dp[2][1 << 10][18], L, c;

int rec(int l, int s, int d, int* A) {
	if (d == L)
		return c == 0;

	int& ret = dp[l][s][d];

	if (ret != -1) 
		return ret;

	ret = 0;
	int i, S = l ? A[d] : 0;

	for (i = S; i < 10; i++) {
		if ((1 << i) & s)
			ret |= rec(l && i == S, s, d + 1, A);
		else if (c) {
			c--;
			ret |= rec(l && i == S, s | (1 << i), d + 1, A);
			c++;
		}
	}

	return ret;
}

void f(int l, int s, int d, int* A) {
	if (d == L) 
		return;

	int& ret = dp[l][s][d];
	int i, S = l ? A[d] : 0;

	for (i = S; i < 10; i++) {
		if (((1 << i) & s)) {
			if (rec(l && i == S, s, d + 1, A)) {
				printf("%d", i);
				f(l && i == S, s, d + 1, A);
				break;
			}
		}
		else if (c) {
			c--;
			if (rec(l && i == S, s | (1 << i), d + 1, A)) {
				printf("%d", i);
				f(l && i == S, s | (1 << i), d + 1, A);
				break;
			}
			c++;
		}
	}
}

int main() {
	int K, A[18], i;
	ll N, t;
	scanf("%lld%d", &N, &K);
	t = N;

	for (i = 0; t; i++) {
		A[i] = t % 10;
		t /= 10;
	}

	L = max(i, K);

	if (i >= K) {
		for (i = 0; i < L / 2; i++) {
			t = A[i];
			A[i] = A[L - 1 - i];
			A[L - 1 - i] = t;
		}
	}
	else {
		A[0] = 1;
		for (i = 1; i < L; i++) A[i] = 0;
	}

	c = K;
	memset(dp, -1, sizeof dp);

	if (rec(1, 0, 0, A))
		f(1, 0, 0, A);
	else {
		A[0] = 1;
		L++;
		for (i = 1; i < L; i++) A[i] = 0;

		memset(dp, -1, sizeof dp);
		rec(1, 0, 0, A);
		f(1, 0, 0, A);
	}

	return 0;
}