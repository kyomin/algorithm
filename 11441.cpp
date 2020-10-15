#include <cstdio>

using namespace std;

int N, M;
int pSum[100001] = { 0, };

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int A;
		scanf("%d", &A);
		pSum[i] = pSum[i - 1] + A;
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", pSum[e] - pSum[s - 1]);
	}

	return 0;
}