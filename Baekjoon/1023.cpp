#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;

ll D[52][130];

int main(void) {
	for (int i = 1; i <= 120; i++) {
		D[1][i] = 2;
		D[0][i] = 1;
	}

	D[0][60] = 0;
	D[1][61] = 1;

	for (int i = 2; i <= 50; i++) {
		for (int j = 1; j < 60; j++)
			D[i][j] = (1ll << i);

		for (int j = 60; j <= 120; j++)
			D[i][j] = D[i - 1][j - 1] + D[i - 1][j + 1];
	}

	ll N, K;
	scanf("%lld %lld", &N, &K);

	if (N % 2 == 0 && K >= D[N][60]) {
		printf("-1");
		return 0;
	}

	ll cnt = 0;
	bool isFail = false;
	int prefix_score = 60;

	for (int i = 1; i <= N; i++) {
		ll cmp_val = D[N - i][prefix_score + 1];

		if (isFail)
			cmp_val = 1ll << (N - i);

		if (cnt + cmp_val > K) {
			prefix_score++;
			printf("(");
		}
		else {
			cnt += cmp_val;
			prefix_score--;
			printf(")");
		}

		if (prefix_score < 60) 
			isFail = true;
	}

	return 0;
}