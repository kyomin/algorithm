#include <iostream>
#include <cstdio>

using namespace std;

int N, M, pSum[100001] = { 0, };

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		int A;
		scanf("%d", &A);
		pSum[i] = pSum[i - 1] + A;
	}

	for (int i = 0; i < M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", pSum[e] - pSum[s - 1]);
	}

	return 0;
}