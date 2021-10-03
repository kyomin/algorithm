#include <iostream>
#include <string>

using namespace std;

const int dr[8] = { 0,0, 1,-1, -1, -1, 1, 1 };
const int dc[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };
string map[100];
string ans[100];
int R, C;

bool isInside(int r, int c) {
	if (0 <= r && r < R && 0 <= c && c < C)
		return true;

	return false;
}

int main() {
	while (true) {
		cin >> R >> C;
		if (R == 0 && C == 0)
			break;

		for (int r = 0; r < R; r++)
			cin >> map[r];

		for (int r = 0; r < R; r++) {
			string row = "";

			for (int c = 0; c < C; c++) {
				char ch = map[r][c];
				
				if (ch == '*') {
					row += "*";
					continue;
				}

				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int nr = r + dr[k];
					int nc = c + dc[k];

					if (!isInside(nr, nc))
						continue;

					if (map[nr][nc] == '*')
						cnt++;
				}

				row += to_string(cnt);
			}

			ans[r] = row;
		}

		for (int r = 0; r < R; r++)
			cout << ans[r] << endl;
	}

	return 0;
}