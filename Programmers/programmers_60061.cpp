#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool pillar[102][102];
bool bar[102][102];

bool checkPillar(int x, int y) {
	// 바닥면 || 기둥 위인 경우
	if (y == 0 || pillar[x][y - 1])
		return true;

	// 보 위인 경우
	if ((x > 0 && bar[x - 1][y]) || bar[x][y])
		return true;

	return false;
}

bool checkBar(int x, int y) {
	// 기둥 위에 설치되는 경우
	if (pillar[x][y - 1] || pillar[x + 1][y - 1])
		return true;

	// 양쪽에 보가 있는 경우
	if (x > 0 && bar[x - 1][y] && bar[x + 1][y])
		return true;

	return false;
}

bool canDelete(int x, int y) {
	for (int i = max(x - 1, 0); i <= x + 1; i++) {
		for (int j = y; j <= y + 1; j++) {
			if (pillar[i][j] && !checkPillar(i, j))
				return false;

			if (bar[i][j] && !checkBar(i, j))
				return false;
		}
	}

	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	memset(pillar, 0, sizeof(pillar));
	memset(bar, 0, sizeof(bar));

	for (auto build : build_frame) {
		int x = build[0];
		int y = build[1];
		int type = build[2];
		int cmd = build[3];

		// 기둥인 경우
		if (type == 0) {
			// 설치인 경우
			if (cmd == 1) {
				if (checkPillar(x, y))
					pillar[x][y] = true;
			}
			// 삭제인 경우
			else {
				pillar[x][y] = false;

				// 삭제 가능하지 않다면 복원
				if (!canDelete(x, y))
					pillar[x][y] = true;
			}
		}
		// 보인 경우
		else {
			// 설치인 경우
			if (cmd == 1) {
				if (checkBar(x, y))
					bar[x][y] = true;
			}
			// 삭제인 경우
			else {
				bar[x][y] = false;

				// 삭제 가능하지 않다면 복원
				if (!canDelete(x, y))
					bar[x][y] = true;
			}
		}
	}

	for (int x = 0; x <= n; x++) {
		for (int y = 0; y <= n; y++) {
			if (pillar[x][y])
				answer.push_back({ x, y, 0 });

			if (bar[x][y])
				answer.push_back({ x, y, 1 });
		}
	}

	return answer;
}