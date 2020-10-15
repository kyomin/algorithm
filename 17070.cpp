#include <iostream>

using namespace std;

struct Position {
	int r;
	int c;
};

int map[17][17];
int ans = 0;
int N;

bool isInside(int r, int c) {
	if (1 <= r && r <= N && 1 <= c && c <= N)
		return true;

	return false;
}

// dir: 0 가로, 1 대각선, 2 세로
void dfs(Position front, Position back, int dir) {
	// 한쪽 끝이 (N, N)에 도달한 경우
	if (back.r == N && back.c == N) {
		ans++;
		return;
	}

	int fr = front.r;
	int fc = front.c;
	int br = back.r;
	int bc = back.c;

	// 가로 방향인 경우
	if (dir == 0) {
		// 경우 1
		if (isInside(br, bc+1) && map[br][bc+1] != 1)
			dfs({ fr, fc + 1 }, { br, bc + 1 }, 0);

		// 경우 2
		if (isInside(br, bc + 1) && isInside(br + 1, bc + 1) && isInside(br + 1, bc) && map[br][bc + 1] != 1 && map[br + 1][bc + 1] != 1 && map[br + 1][bc] != 1)
			dfs({ fr, fc + 1 }, { br + 1, bc + 1 }, 1);
	}

	// 대각선 방향인 경우
	if (dir == 1) {
		// 경우 1
		if (isInside(br, bc + 1) && map[br][bc + 1] != 1)
			dfs({ fr + 1, fc + 1 }, { br, bc + 1 }, 0);

		// 경우 2
		if (isInside(br + 1, bc) && map[br + 1][bc] != 1)
			dfs({ fr + 1, fc + 1 }, { br + 1, bc }, 2);

		// 경우 3
		if (isInside(br, bc + 1) && isInside(br + 1, bc + 1) && isInside(br + 1, bc) && map[br][bc + 1] != 1 && map[br + 1][bc + 1] != 1 && map[br + 1][bc] != 1)
			dfs({ fr + 1, fc + 1 }, { br + 1, bc + 1 }, 1);
	}

	// 세로 방향인 경우
	if (dir == 2) {
		// 경우 1
		if (isInside(br + 1, bc) && map[br + 1][bc] != 1)
			dfs({ fr + 1, fc }, { br + 1, bc }, 2);

		// 경우 2
		if (isInside(br, bc + 1) && isInside(br + 1, bc + 1) && isInside(br + 1, bc) && map[br][bc + 1] != 1 && map[br + 1][bc + 1] != 1 && map[br + 1][bc] != 1)
			dfs({ fr + 1, fc }, { br + 1, bc + 1 }, 1);
	}
}

int main() {
	cin >> N;

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			cin >> map[r][c];

	int fr = 1, fc = 1, br = 1, bc = 2;

	dfs({ fr, fc }, { br, bc }, 0);

	cout << ans << '\n';

	return 0;
}