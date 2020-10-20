#include <iostream>
#include <cstdio>

using namespace std;

int R, C, Q;
int pSum[1000][1001];

int main() {
	scanf("%d %d %d", &R, &C, &Q);

	for (int i = 0; i < R; i++) {
		for (int j = 1; j <= C; j++) {
			int A;
			scanf("%d", &A);
			pSum[i][j] = pSum[i][j - 1] + A;
		}
	}

	for (int i = 0; i < Q; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int sum = 0;
		int dividend = (x2 - x1 + 1)*(y2 - y1 + 1);

		for (int i = x1 - 1; i <= x2 - 1; i++)
			sum += (pSum[i][y2] - pSum[i][y1 - 1]);

		printf("%d\n", sum / dividend);
	}

	return 0;
}