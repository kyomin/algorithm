#include <iostream>
#include <cstdio>

using namespace std;

int N, M;
int pSum[1024][1025] = {
	{0,},
};

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			int A;
			scanf("%d", &A);
			pSum[i][j] = pSum[i][j - 1] + A;
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int sum = 0;

		for (int i = x1 - 1; i <= x2 - 1; i++)
			sum += (pSum[i][y2] - pSum[i][y1 - 1]);

		printf("%d\n", sum);
	}

	return 0;
}