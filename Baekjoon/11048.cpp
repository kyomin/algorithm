#include <iostream>
#include <algorithm>

using namespace std;

int DP[1001][1001];
int N, M;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> DP[i][j];

			DP[i][j] += max(DP[i - 1][j], max(DP[i - 1][j - 1], DP[i][j - 1]));
		}
	}

	cout << DP[N][M] << '\n';

	return 0;
}