#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 15;

int map[MAX][MAX];

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, M;
		cin >> N >> M;

		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				cin >> map[r][c];

		int ans = 0;

		for (int r = 0; r <= N - M; r++) {
			for (int c = 0; c <= N - M; c++) {
				int sum = 0;

				for (int i = r; i < r + M; i++)
					for (int j = c; j < c + M; j++)
						sum += map[i][j];

				ans = max(ans, sum);
			}
		}

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}