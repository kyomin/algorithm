#include <iostream>

using namespace std;

int map[100][100];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int R, C;
		cin >> R >> C;

		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				cin >> map[r][c];

		int dist = 0;

		for (int c = 0; c < C; c++) {
			for (int r = (R - 1); r > 0; r--) {
				if (map[r][c] != 0)
					continue;

				for (int k = r - 1; k >= 0; k--) {
					if (map[k][c] != 0) {
						int temp = map[r][c];
						map[r][c] = map[k][c];
						map[k][c] = temp;
						
						dist += (r - k);

						break;
					}
				}
			}
		}

		cout << dist << '\n';
	}

	return 0;
}