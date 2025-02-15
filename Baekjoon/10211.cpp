#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

const int MIN = numeric_limits<int>::min();

int A[1000];
int N;

int MaxSum() {
	int ret = MIN, pSum = 0;

	for (int i = 0; i < N; i++) {
		pSum = max(pSum, 0) + A[i];
		ret = max(ret, pSum);
	}

	return ret;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);

		printf("%d\n", MaxSum());
	}

	return 0;
}